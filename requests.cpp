#include <curl/curl.h>
#include <curl/easy.h>
#include <string>
#include <tuple>
#include <cstring>


#include "parse.h"
//a enlever ;
#include <iostream>

#define API_KEY "752d26308bcec67eb884e7fef8f566b9"
std::string curlRequest(std::string city){

  CURL *curl = curl_easy_init();
  CURLcode res; 
  
  std::string url = "http://api.openweathermap.org/geo/1.0/direct?q="+city+"&limit=1&appid="+API_KEY;
  if(curl){
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }
    curl_easy_cleanup(curl);
  }
  const char *str = curl_easy_strerror(res);
  return str;
}

std::tuple<double, double> getCoordinates(std::string city){
  double lat;
  double lon;
  
  std::string toJson = curlRequest(city);

  return std::make_tuple(lat,lon);


}
