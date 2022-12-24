#include <cmath>

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
