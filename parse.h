#include <rapidjson/document.h>
#include <string>
class Parse{

// private:
//   std::string reqResponse;

public:
  double parseJson(std::string reqResponse){
    std::string reqConcat = "R" + reqResponse;
    
    rapidjson::Document doc;
    doc.Parse(reqConcat.c_str());
    
    double lat = doc[0]["lat"].GetDouble();
    double lon = doc[0]["lat"].GetDouble();

    return lat;
  }
};




