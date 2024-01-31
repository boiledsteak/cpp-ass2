#include "rectangle.h"
#include <algorithm>
#include <sstream>

using namespace std;
//default constructor
Rectangle::Rectangle() {}

double Rectangle::computeArea() const
{
    // Assuming the input coordinates are in any order
    int minX = -99;
    int minY = -99;
    int maxX = 99;
    int maxY = 99;

    for (const auto &coord : getCoordinates())
    {
        minX = min(minX, coord.first);
        minY = min(minY, coord.second);
        maxX = max(maxX, coord.first);
        maxY = max(maxY, coord.second);
    }

    int length = maxX - minX;
    int width = maxY - minY;
    return static_cast<double>(length * width);
}

bool Rectangle::isPointInShape(int x, int y) const
{
    // Assuming the input coordinates are in any order
    int minX = -99;
    int minY = -99;
    int maxX = 99;
    int maxY = 99;

    for (const auto &coord : getCoordinates())
    {
        minX = min(minX, coord.first);
        minY = min(minY, coord.second);
        maxX = max(maxX, coord.first);
        maxY = max(maxY, coord.second);
    }

    bool insideRectangle = (x > minX) && (x < maxX) && (y > minY) && (y < maxY);

    return insideRectangle;
}

bool Rectangle::isPointOnShape(int x, int y) const
{
    for (int i = 0; i < numCoordinates; ++i)
    {
        int x1 = getCoordinates()[i].first;
        int y1 = getCoordinates()[i].second;
        int x2 = getCoordinates()[(i + 1) % numCoordinates].first; // Wrap around to the first coordinate for the last edge
        int y2 = getCoordinates()[(i + 1) % numCoordinates].second;

        // Check if the point is on the line segment defined by (x1, y1) and (x2, y2)
        if ((x >= min(x1, x2) && x <= max(x1, x2)) && (y >= min(y1, y2) && y <= max(y1, y2)))
        {
            // Check if the point is on the edge (excluding the corners)
            if ((x == x1 || x == x2) && (y > min(y1, y2) && y < max(y1, y2)) ||
                (y == y1 || y == y2) && (x > min(x1, x2) && x < max(x1, x2)))
            {
                return true;
            }
        }
    }

    return false;
}

string Rectangle::toString() const
{
    stringstream ss;
    ss << ShapeTwoD::toString(); // Call the parent toString function
    int counts = 0;
    for (const auto &coord : getCoordinates())
    {
        ss << "Point [" << counts << "] : " << "(" << coord.first << ", " << coord.second << ")\n";
        counts++;
    }

    return ss.str();
}

int Rectangle::getNumCoordinates() const
{
    return numCoordinates;
}
