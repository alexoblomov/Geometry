//
// Created by alex on 04/10/2019.
//

#include "PointSet.h"
#include <iterator>

template <class T>
PointSet<T>::PointSet() {
int size = 5;
for (unsigned i = 0; i< size; i++)
{
    Point2D point;
    m_set->insert(point);
}

}

template<class T>
PointSet<T>::~PointSet() {

}

//template<class T>
//PointSet &PointSet<T>::operator=(PointSet other) {
//}

template<class T>
void PointSet<T>::clear() {

}

template<class T>
void PointSet<T>::insert(size_t, const T &) {

}

template<class T>
void PointSet<T>::emplace() {

}

template<class T>
void PointSet<T>::erase(size_t) {

}

//void PointSet::printset(const PointSet &pointSet) {
//    for (const auto & value : pointSet)
//    {
//        std::cout << value;
//    }
//}
//
//std::ostream &operator<<(std::ostream &out, const PointSet &pointSet)
//{
//    for(const auto &p : pointSet)
//    {
//        out << p << std::endl;
//    }
//    return out;
//}
