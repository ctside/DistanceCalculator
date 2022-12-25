#include <iostream>
#include <curl/curl.h>
#include <string>
#include <tuple>

#include "point.h"
#include "requests.h"
#include "parse.hjlasf"

// http://api.openweathermap.org/geo/1.0/direct?q=mons&limit=5&appid=752d26308bcec67eb884e7fef8f566b9 lol
// https://openweathermap.org/api/geocoding-api




int main(int argc,char **argv){
  
  // Point npc1(1,1);
  // Point npc2(2,2);

  // std::cout << npc1.getDistance(npc2) << std::endl;

  // std::tuple<double> tup = std::get<0>(getCoordinates("test"));
  // double lng = std::get<double>(tup);

  // std::cout << lng << std::endl;
  //
  // if((argc >= 2) and (argc <=3)) {
  // std::string city1 = argv[1];
  // std::string city2 = argv[2];
  // getCoordinates(city1);

  // }
  // else if(argc <= 2){
  // std::cout << "Cities parameter missing" << std::endl << "Please use the command as following : " << argv[0] << " city1 city2" << std::endl;
  // }
  // else{
  // std::cout << "An error occured" << std::endl;
  } 
