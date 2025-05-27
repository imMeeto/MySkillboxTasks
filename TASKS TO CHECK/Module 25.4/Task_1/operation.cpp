#include "operation.h"
#include <iostream>
#include <string>

Point inputPoint(const std::string& prompt)
{
    Point p;
    std::cout << prompt << " (x y): ";
    std::cin >> p.x >> p.y;
    return p;
}

void printPoint(const Point& p)
{
    std::cout << "(" << p.x << ", " << p.y << ")";
}

bool arePointsEqual(const Point& a, const Point& b)
{
    return a.x == b.x && a.y == b.y;
}

void scalpel(const Point& start, const Point& end)
{
    std::cout << "Made an incision from ";
    printPoint(start);
    std::cout << " to ";
    printPoint(end);
    std::cout << std::endl;
}

void hemostat(const Point& position)
{
    std::cout << "Applied hemostat at point ";
    printPoint(position);
    std::cout << std::endl;
}

void tweezers(const Point& position) {
    std::cout << "Used tweezers at point ";
    printPoint(position);
    std::cout << std::endl;
}

void suture(const Point& start, const Point& end) {
    std::cout << "Sutured from ";
    printPoint(start);
    std::cout << " to ";
    printPoint(end);
    std::cout << std::endl;
}

int main() {
    Point startScalpel, endScalpel;

    std::cout << "*** Simulator of operations. ***\n";
    std::cout << "Operation begins.\n";
    startScalpel = inputPoint("Enter incision start point");
    endScalpel = inputPoint("Enter incision end point");
    scalpel(startScalpel, endScalpel);

    std::string command;
    while (true) {
        std::cout << "\nAvailable commands: scalpel, hemostat, tweezers, suture\n";
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "scalpel") {
            Point start, end;
            start = inputPoint("Enter incision start point");
            end = inputPoint("Enter incision end point");
            scalpel(start, end);
        } else if (command == "hemostat") {
            Point position;
            position = inputPoint("Enter point for hemostat");
            hemostat(position);
        } else if (command == "tweezers") {
            Point position;
            position = inputPoint("Enter point for tweezers");
            tweezers(position);
        } else if (command == "suture") {
            Point start, end;
            start = inputPoint("Enter suture start point");
            end = inputPoint("Enter suture end point");

            if (arePointsEqual(start, startScalpel) && arePointsEqual(end, endScalpel)) {
                suture(start, end);
                std::cout << "\nOperation completed successfully.\n";
                break;
            } else {
                std::cout << "Error: suture must match the initial incision!\n";
            }
        } else {
            std::cout << "Unknown command. Please try again.\n";
        }
    }

    return 0;
}