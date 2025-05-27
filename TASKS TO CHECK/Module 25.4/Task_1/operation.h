#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <cmath>
#include <string>

struct Point {
    double x;
    double y;
};

Point inputPoint(const std::string& prompt);

void printPoint(const Point& p);

// cравнение точек (с учетом погрешности для double)
bool arePointsEqual(const Point& a, const Point& b);

void scalpel(const Point& start, const Point& end);
void hemostat(const Point& position);
void tweezers(const Point& position);
void suture(const Point& start, const Point& end);

#endif