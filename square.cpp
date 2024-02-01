#include "square.h" 
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;
//default constructor
Square::Square() {}

double Square::computeArea() const
{
    // Assuming the input coordinates are in any order, find the min and max coordinates
    int minX = numeric_limits<int>::max();
    int minY = numeric_limits<int>::max();
    int maxX = numeric_limits<int>::min();
    int maxY = numeric_limits<int>::min();

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

bool Square::isPointInShape(int x, int y) const
{
    // Assuming the input coordinates are in any order, find the min and max coordinates
    int minX = numeric_limits<int>::max();
    int minY = numeric_limits<int>::max();
    int maxX = numeric_limits<int>::min();
    int maxY = numeric_limits<int>::min();

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

bool Square::isPointOnShape(int x, int y) const
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

string Square::toString() const
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

int Square::getNumCoordinates() const
{
    return numCoordinates;
}
