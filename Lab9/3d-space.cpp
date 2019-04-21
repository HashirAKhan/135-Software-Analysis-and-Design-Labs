//Name: Hashir Khan
//Lab 9A-C, E
//CSCI 135
//04-11-19


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
//declares the class Coord3D
class Coord3D {
public:
    double x; //makes x,y,z doubles
    double y;
    double z;
};

double length(Coord3D *p){ //this does the calculations for the distance formula
   double x2 = p -> x;
   double y2 = p -> y;
   double z2 = p -> z;

	return sqrt((x2 * x2) + (y2 * y2) + (z2 * z2)); //sqrt of x^2 y2 ect ect
}

Coord3D* fartherFromOrigin(Coord3D *p1, Coord3D *p2){ //now we're calculating
//the coordinates of two points and returns the pointers that is furthest away from the origin
   double dist1 = length(p1);
   double dist2 = length(p2);

   if (dist1 > dist2){
      return p1;
   } else {
      return p2;
   }
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){ //velocity!!
   ppos -> x = (ppos -> x) + (pvel -> x) * dt;
   ppos -> y = (ppos -> y) + (pvel -> y) * dt;
   ppos -> z = (ppos -> z) + (pvel -> z) * dt;
}

Coord3D* createCoord3D(double x, double y, double z){
   Coord3D *p = new Coord3D;
   p -> x = x;
   p -> y = y;
   p -> z = z;

   return p;
}

void deleteCoord3D(Coord3D *p){
   delete p;
   p = nullptr;
}
