#include <iostream>
#include "polygon.hpp"
#include <vector>

using namespace std;

int main(){

     Point p1(5,4);
     Point p2(6,2);
     Point p3(8,1);
     Point p4(11,4);
     Point p5(10,6);
     Point p6(9,6);
     Point p7(8,5);
     Point p8(9,4);
     Point p9(7,4);
     Point p10(6,4.5);

    Point a(7.25,4.68);

    vector <Point> poly;

    poly.push_back(p1);
    poly.push_back(p2);
    poly.push_back(p3);
    poly.push_back(p4);
    poly.push_back(p5);
    poly.push_back(p6);
    poly.push_back(p7);
    poly.push_back(p8);
    poly.push_back(p9);
    poly.push_back(p10);
    poly.push_back(p1);

   Polygon poly2(poly);

   cout << "Ponto: (" << a.get_x() << "," << a.get_y() << ")" << endl;

   cout << "Polígono é: " << (poly2.convex() ? "Convexo" : "Concavo")  << endl;

   cout << "Ponto " << "(" << a.get_x() << "," << a.get_y() << ") está: " << (poly2.contains(a) ? "Dentro" : "Fora") << endl;

    return 0;
}
