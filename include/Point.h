
#ifndef _POINT_H_
#define _POINT_H_
#include <iostream>
class Point{
    private:
        int x;  
        int y;
    public:
        Point(int x, int y);
        Point(const Point& p);
};

Point::Point(int x, int y):x(x), y(y){
    std::cout << "Constructor called" << std::endl;
}

Point::Point(const Point& p):x(p.x), y(p.y){
    std::cout << "Copy constructor called" << std::endl;
}

#endif _POINT_H_
