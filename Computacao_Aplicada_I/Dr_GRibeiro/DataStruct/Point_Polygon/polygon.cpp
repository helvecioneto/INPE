#include "polygon.hpp"
#include <iostream>
#include <cmath>


Point::Point(double x, double y){
    this->x_ = x;
    this->y_ = y;
    
}

const double Point::get_x() const {
    return this->x_;
}

const double Point::get_y() const {
    return this->y_;
}


Polygon::Polygon(const std::vector<Point> ps){
    vs = ps;
    n = vs.size();
    vs.push_back(vs.front());
    std::cout << "Poligono criado, tamanho:" << n << std::endl;
    std::cout << "Vertices: ";
    for (int i = 0; i < n; ++i){
        std::cout << "(" << ps[i].get_x() << "," << ps[i].get_y() << ")" ;
    }
    std::cout << std::endl;
}

auto Polygon::orientation(const Point& P, const Point& Q, const Point& R) const{

    //return ( Q.get_y() - P.get_y()) * ( R.get_x() - Q.get_x() ) - 
    //       ( Q.get_x() - P.get_x()) * ( R.get_y() - Q.get_y() );

    return ( P.get_x() * Q.get_y() + P.get_y() * R.get_x() + Q.get_x() * R.get_y() ) - 
           ( R.get_x() * Q.get_y() + R.get_y() * P.get_x() + Q.get_x() * P.get_y() );
}

bool Polygon::convex() const{
    if (n < 3 )     return false;

    int P = 0, N = 0, Z = 0;

    for ( int i = 0; i < n; ++i){
        auto d = orientation(vs[i] , vs[(i + 1) % n], vs[(i + 2) % n]);
        d ? (d > 0 ? ++ P : ++ N) : ++ Z;
    }
    return not ((P and N) or (P == 0 and N == 0));
}

double Polygon::AngleTest(const Point P, const Point A, const Point B){

    auto ux = P.get_x() - A.get_x();
    auto uy = P.get_y() - A.get_y();

    //std::cout << ux << std::endl;

    auto vx = P.get_x() - B.get_y();
    auto vy = P.get_y() - B.get_y();

    auto num = ux * vx + uy * vy;
    auto den = hypot(ux,uy) * hypot(vx, vy);

    return acos(num/den);
}

//Verifica se pontos não são iguais
bool Polygon::equals( double x, double y){

    return abs(x - y) < EPS;
}

bool Polygon::contains(const Point P){

    if (n < 3)
        return false;

    auto sum = 0.0;

    for (int i = 0; i < n; ++i){

        auto d = orientation(P, vs[i], vs[i + 1]);

        //std::cout << "\nValor de P: " << vs[i + i].get_x() << std::endl;

        if (equals(d,0))
            return true;

        auto a = AngleTest(P, vs[i], vs[i + 1]);
        sum += d > 0 ? a : -a;
        
    }

    static const double PI = acos(-1.0);

    //std::cout << PI << std::endl;
    return equals(fabs(sum), 2*PI);
}