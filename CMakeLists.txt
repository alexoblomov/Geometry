cmake_minimum_required(VERSION 3.15)
project(ConvHull2D)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConvHull2D main.cpp Point2D.cpp Point2D.h PointSet.cpp PointSet.h)