//
// Created by alex on 04/10/2019.
//

#ifndef CONVHULL2D_POINT2D_H
#define CONVHULL2D_POINT2D_H

#include <iostream>

class Point2D {
    friend std::ostream & operator << (std::ostream &out, const Point2D &p);
    friend  bool operator< (const Point2D &p1, const Point2D &p2);

public:
    Point2D();
    Point2D(const Point2D& p);
    ~Point2D(){};
    Point2D & operator=(const Point2D& p);
    float x;
    float y;
};


#endif //CONVHULL2D_POINT2D_H
