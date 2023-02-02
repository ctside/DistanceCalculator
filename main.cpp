#include <cmath>
#include <cstring>
#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <iterator>
// #include <rapidjson/document.h>
// #include <json/json.h>
#include <nlohmann/json.hpp>
#include <numbers>
#include <string>
#include <tuple>
#include <vector>

#define API_KEY "752d26308bcec67eb884e7fef8f566b9"

using namespace nlohmann;

// HACK: prevent curl from using standard output :

static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                            void *userp) {
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

std::string curlRequest(std::string city) {
  CURL *curl;
  CURLcode res;
  std::string response;

  std::string url = "http://api.openweathermap.org/geo/1.0/direct?q=" + city +
                    "&limit=1&appid=" + API_KEY;
  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
      std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res)
                << std::endl;
    }
    curl_easy_cleanup(curl);
    return response;
  }
  curl_global_cleanup();
  return 0;
}

class Parse {

private:
  std::string reqCity;

public:
  Parse(std::string city) { reqCity = curlRequest(city); }
  std::vector<double> parseJson() {
    //
    // HACK: somehow the api returns an array even when there's only a single
    // city, so we have to retrieve the index 0, plus this will prevent
    // undefined behaviour in case of multiple occurence returned by the api
    //
    auto req = json::parse(reqCity)[0];

    std::vector<double> latLon = {req.at("lat"), req.at("lon")};

    return latLon;
  }
};

class Distance {
private:
  double lat1;
  double lon1;

  double lat2;
  double lon2;

public:
  Distance(std::string city1, std::string city2) {

    Parse p1 = Parse(city1);
    Parse p2 = Parse(city2);
    lat1 = p1.parseJson()[0];
    lon1 = p1.parseJson()[1];
    lat2 = p2.parseJson()[0];
    lon2 = p2.parseJson()[1];
  }
  double getDistance() {
    // using haversine formula since the earth isnt flat
    lat1 *= std::numbers::pi / 180;
    lat2 *= std::numbers::pi / 180;
    lon1 *= std::numbers::pi / 180;
    lon2 *= std::numbers::pi / 180;

    double deltaLong = (lon2 - lon1);
    double deltaLat = (lat2 - lat1);

    short R = 6371; // earth radius
    double a = std::sin(deltaLat / 2) * std::sin(deltaLat / 2) +
               std::cos(lat1) * std::cos(lat2) * sin(deltaLong / 2) *
                   sin(deltaLong / 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    return R * c;
  }
};

int main(int argc, char **argv) {
  if (argc == 3) {

    // Parse p2 = Parse(argv[2]);
    // std::cout << p1.parseJson()[0] << ":" << p1.parseJson()[1] << std::endl;

    // std::cout << p2.parseJson()[0] << ":" << p2.parseJson()[1] << std::endl;

    Distance p1 = Distance(argv[1], argv[2]);
    std::cout << p1.getDistance();
  } else {
    std::cout << "Wrong usage" << std::endl
              << "Please use the command as following : " << argv[0]
              << " city1 city2" << std::endl;
  }
  return 0;
}
