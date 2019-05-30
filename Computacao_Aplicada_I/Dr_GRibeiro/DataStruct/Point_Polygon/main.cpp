#include <iostream>
#include "polygon.hpp"
#include <vector>

using namespace std;

int main(){

    Point p1(0,0);
    Point p2(10,0);
    Point p3(10,10);
    Point p4(0,10);
    //Point p5(5,5);

    Point a(500,20);

    vector <Point> poly;

    poly.push_back(p1);
    //poly.push_back(p5);
    poly.push_back(p2);
    poly.push_back(p3);
    poly.push_back(p4);
    poly.push_back(p1);

   Polygon poly2(poly);
   cout << "Ponto: (" << a.get_x() << "," << a.get_y() << ")" << endl;

   cout << "Polígono é: " << (poly2.convex() ? "Convexo" : "Concavo")  << endl;

   cout <<  "Ponto " << "(" << a.get_x() << "," << a.get_y() << ") está: " << (poly2.contains(a) ? "Dentro" : "Fora") << endl;

    return 0;
}