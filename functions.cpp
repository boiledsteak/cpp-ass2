#include "functions.h"
#include "circle.h" 
#include "square.h"
#include "rectangle.h"
#include "cross.h"

#include <iostream>
#include <algorithm>
#include <limits>

void menuprinter() 
{
    cout << "\n\n\n";
    cout << "Student ID:" << "\t10258663\n";
    cout << "Student name:" << "\tTimothy Mah\n";
    cout << "------------------------------------------------------\n";
    cout << "Welcome to Assignment 2 program!\n\n";
    cout << "1)" << "\tInput sensor data\n"; //the input coords will always be adjacent and clockwise
    cout << "2)" << "\tCompute area (for all records)\n"; // should apply polymorphism and dynamic binding. There should  only be one array. Not one array for each shape
    cout << "3)" << "\tPrint shapes report\n"; 
    cout << "4)" << "\tSort shape data\n"; // sort by special type and area.
    cout << "5)" << "\tExit\n";
    cout << "\n\nTell me what you want!\n\n";
}

void smallmenuprinter() 
{
    cout << "\ta.\tSort by area (ascending)\n";
    cout << "\tb.\tSort by area (descending)\n";
    cout << "\tc.\tSort by special type and area\n";
    cout << "\nPlease select option ('q' to go main menu)\n\n";
}

bool compareShapesByArea(const ShapeTwoD* a, const ShapeTwoD* b, bool ascending) 
{
    return ascending ? (a->computeArea() < b->computeArea()) : (a->computeArea() > b->computeArea());
}

void printCoordinatesInfo(const ShapeTwoD* shape, int& minX, int& minY, int& maxX, int& maxY, bool& hasPointsInside, bool& hasPointsOnShape) 
{
    for (int x = minX; x <= maxX; ++x) 
    {
        for (int y = minY; y <= maxY; ++y) 
        {
            if (shape->isPointOnShape(x, y) && find(shape->getCoordinates().begin(), shape->getCoordinates().end(), make_pair(x, y)) == shape->getCoordinates().end()) 
            {
                cout << "(" << x << ", " << y << ") ";
                hasPointsOnShape = true;
            }
        }
    }

    if (!hasPointsOnShape) 
    {
        cout << " none!";
    }

    cout << "\n";

    cout << "Points within shape:\t";

    for (const auto& coord : shape->getCoordinates()) 
    {
        if (shape->isPointInShape(coord.first, coord.second)) 
        {
            cout << "(" << coord.first << ", " << coord.second << ") ";
            hasPointsInside = true;
            // Update min and max coordinates for the bounding box
            minX = min(minX, coord.first);
            minY = min(minY, coord.second);
            maxX = max(maxX, coord.first);
            maxY = max(maxY, coord.second);
        }
    }

    // Print additional coordinates inside the area that were not input by the user
    for (int x = minX; x <= maxX; ++x) 
    {
        for (int y = minY; y <= maxY; ++y) 
        {
            if (shape->isPointInShape(x, y) && find(shape->getCoordinates().begin(), shape->getCoordinates().end(), make_pair(x, y)) == shape->getCoordinates().end()) 
            {
                cout << "(" << x << ", " << y << ") ";
                hasPointsInside = true;
            }
        }
    }

    if (!hasPointsInside) 
    {
        cout << "none!";
    }

    cout << "\n";
}

void printShapeInfo(const ShapeTwoD* shape, int counter) 
{
    cout << "Shape [" << counter << "]\n";
    cout << shape->toString() << "\n";
    
    // Initialize bounding box
    int minX = numeric_limits<int>::max();
    int minY = numeric_limits<int>::max();
    int maxX = numeric_limits<int>::min();
    int maxY = numeric_limits<int>::min();

    bool hasPointsInside = false;
    bool hasPointsOnShape = false;

    // check if shape object is circle
    if (const auto *circle = dynamic_cast<const Circle *>(shape))
    {
        int cx, cy, r;
        pair<int, int> center = circle->getCoordinates()[0];
        r = circle->getRadius();
        cx = center.first;
        cy = center.second;
        // Update bounding box based on circle properties
        minX = min(minX, cx - r);
        minY = min(minY, cy - r);
        maxX = max(maxX, cx + r);
        maxY = max(maxY, cy + r);
    }

    // Update bounding box for non circle shapes
    for (const auto &coord : shape->getCoordinates())
    {
        // Update min and max coordinates for the bounding box
        minX = min(minX, coord.first);
        minY = min(minY, coord.second);
        maxX = max(maxX, coord.first);
        maxY = max(maxY, coord.second);
    }

    // Print all coordinates on the shape
    cout << "Points on perimeter:\t";
    printCoordinatesInfo(shape, minX, minY, maxX, maxY, hasPointsInside, hasPointsOnShape);

    cout << "\n\n\n";
}

bool compareShapes(const ShapeTwoD* a, const ShapeTwoD* b) 
{
    if (a->getContainsWarpSpace() == b->getContainsWarpSpace()) 
    {
        return a->computeArea() > b->computeArea();
    } 
    else 
    {
        return a->getContainsWarpSpace() > b->getContainsWarpSpace();
    }
}
