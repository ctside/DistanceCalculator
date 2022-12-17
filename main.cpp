#include <iostream>
#include <cmath>
#include <curl/curl.h>

#define API_KEY = "752d26308bcec67eb884e7fef8f566b9"
// http://api.openweathermap.org/geo/1.0/direct?q=mons&limit=5&appid=752d26308bcec67eb884e7fef8f566b9 lol
// https://openweathermap.org/api/geocoding-api

class Point{
public:

  //Constructors
  Point(){
    x = 0;
    y = 0;
  }
  Point(double X,double Y){
    x = X;
    y = Y;
  }
  //getters and setters
  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
  //functions
  double getDistance(Point pnj){
    // d=√((x_2-x_1)²+(y_2-y_1)²)   
    double deltaX = std::pow((pnj.getX() - x), 2);
    double deltaY = std::pow((pnj.getY() - y), 2);
    double distance = std::sqrt(deltaX + deltaY );
    return distance;
  }

private:
  double x;
  double y;

};

double apiCall(std::string city){
  double lat;
  double lon;

  lon = 3.33;
  return lat;
}


int main(){

  Point npc1(1,1);
  Point npc2(2,2);

  std::cout << npc1.getDistance(npc2);
  return 0;
}
