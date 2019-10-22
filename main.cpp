#include <iostream>
#include <bits/unique_ptr.h>
#include "Point2D.h"
#include "PointSet.h"
#include <set>
#include <algorithm>
#include <cmath>

void FillSet(unsigned int size, std::set<Point2D> &set)
{
    for(int s_iter = 0; s_iter < size; s_iter++)
    {
        Point2D point;
        //std::cout << point <<std::endl;
        set.insert(point);
    }
    return;
}

void SubSet(std::set<Point2D> &set, std::set<Point2D> &subset, Point2D&a, Point2D& b)
{
    float slope = (b.y - a.y)/(b.x - a.x);
    float intercept = a.y - slope * a.x;

    for(auto point : set)
    {
        if(point.y > (slope*point.x + intercept)) subset.insert(point);
    }

}

float dist(Point2D &p, Point2D &a, Point2D&b )
{
    float area_by2 = std::abs(a.x*(p.y-b.y )+ p.x*(b.y-a.y) + b.x*(a.y-p.y));
    float norm_ab = std::sqrt(std::pow(b.y-a.y,2)+std::pow(b.x-a.x,2));
    return area_by2/(norm_ab+1); // avoid division by zero
}

void FindHull(std::set<Point2D> &set, Point2D &a, Point2D &b, std::set<Point2D> &conv_hull)
{
    if(set.empty()) return;

    Point2D maxpoint(*set.begin());
    for (auto point: set)
    {
        if(dist(point, a, b ) > dist(maxpoint, a , b))
            maxpoint = point;
    }
    conv_hull.insert(maxpoint);

    std::set<Point2D> S1,S2;
    SubSet(set, S1, a, b);
    std::set_difference(set.begin(), set.end(), S1.begin(), S1.end(), std::inserter(S2,S2.end()));
    std::cout << "s1" << std::endl;
    if(S1.empty())  return;
    if(S2.empty())  return;
    for(auto point : S1)
    {
        std::cout << point << std::endl;
    }
    std::cout << "s2" << std::endl;
    for(auto point : S2)
    {
        std::cout << point << std::endl;
    }
    FindHull(S1,a,maxpoint, conv_hull);
    FindHull(S2,maxpoint,b, conv_hull);
}

void QuickHull(std::set<Point2D> &set, std::set<Point2D> &conv_hull)
{
    if(set.size() < 3) return;
    auto left = *set.begin();
    auto right = *--set.end();
    conv_hull.insert(left);
    conv_hull.insert(right);
    // get all points whose y value lies above the line ab
    std::set<Point2D> S1, S2;
    SubSet(set, S1, left, right);
    // and below
    std::set_difference(set.begin(), set.end(), S1.begin(), S1.end(), std::inserter(S2,S2.end()));
    FindHull(S1, left, right, conv_hull);
    FindHull(S2, left, right, conv_hull);

}


int main() {

    std::cout << "set" << std::endl;
    std::set<Point2D> s;
    FillSet(10, s);

    std::cout << "ok";
    for(auto point : s)
    {
        std::cout << point << std::endl;
    }

    std::set<Point2D> conv_hull;
    QuickHull(s, conv_hull);

    std::cout << "hull";

    for(auto point : conv_hull)
    {
        std::cout << point << std::endl;
    }
    std::cout<< "conv hull size " << conv_hull.size() << std::endl;
    return 0;
}