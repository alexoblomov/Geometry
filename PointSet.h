//
// Created by alex on 04/10/2019.
//

#ifndef CONVHULL2D_POINTSET_H
#define CONVHULL2D_POINTSET_H

#include <iostream>
//#include <set>
//#include <vector>
#include "Point2D.h"

template <class T>
class PointSet {
//friend std::ostream & operator << (std::ostream &out, const PointSet &pointSet);

public:
    PointSet();
//    PointSet(const PointSet& other);
    ~PointSet();
//    PointSet &operator=(PointSet other);
    void clear();
    void insert(size_t, const T&);
    void emplace();
    void erase(size_t);

//    friend void swap(PointSet&, PointSet&);

protected:
//    std::set<Point2D> * s;
//    std::set<Point2D> s;
    T *m_set;
    size_t set_size;

};


#endif //CONVHULL2D_POINTSET_H
