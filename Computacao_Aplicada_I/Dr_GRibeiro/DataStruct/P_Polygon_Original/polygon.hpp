#ifndef __POLYGON_HPP_
#define __POLYGON_HPP__
#include <vector>
#define EPS 1e-9


class Point
{
    private:
        double x_, y_;
    public:
        Point(double x, double y);
        const double get_x() const;
        const double get_y() const;
};


class Polygon
{

    public:
        std::vector<Point> vs;
        int n; 
        Polygon(const std::vector<Point> ps);

        auto orientation(const Point& P, const Point& Q, const Point& R) const;              // Orientação do Poligono
        bool convex() const;                                                                // Verifica convex

    //Point in Polygons
        double AngleTest(const Point P, const Point A, const Point B);
        bool equals(double x, double y);
        bool contains(const Point P);

        //double distance(cosnt Point)
};




#endif // __POLYGON_HPP__
