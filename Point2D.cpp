//
// Created by alex on 04/10/2019.
//

#include "Point2D.h"
#include <random>
#include <iostream>



Point2D::Point2D() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::normal_distribution<double> normal_dist(0, 10);

    x = normal_dist(rng);
    y = normal_dist(rng);

}

Point2D::Point2D(const Point2D& p)
{
    x = p.x;
    y = p.y;
}

std::ostream &operator<<(std::ostream &out, const Point2D &p) {
    out << "x : " << p.x << " y : "<< p.y;
    return out;
}

bool operator<(const Point2D &p1, const Point2D &p2) {
    if (p1.x < p2.x)
        return true;
    else if (p1.x == p2.x && p1.y < p2.y)
        return true;
    return false;
}

Point2D &Point2D::operator=(const Point2D &p) {
    if(this == &p)
        return *this;
    x = p.x;
    y = p.y;

    return *this;
}
