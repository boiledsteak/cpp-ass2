#include "cross.h"
#include <algorithm>
#include <sstream>


Cross::Cross() {}

double Cross::computeArea() const
{
    double rectangleArea = 0.0;
    vector<pair<int, int>> sortedCoordinates = coordinates;
    sort(sortedCoordinates.begin(), sortedCoordinates.end());

    for (int i = 0; i < numCoordinates; i += 4)
    {
        int x1 = sortedCoordinates[i].first;
        int y1 = sortedCoordinates[i].second;
        int x2 = sortedCoordinates[i + 2].first;
        int y2 = sortedCoordinates[i + 2].second;

        rectangleArea += abs(x2 - x1) * abs(y2 - y1);
    }

    return rectangleArea;
}

bool Cross::isPointInShape(int x, int y) const
{
    // Iterate over the rectangles that make up the cross
    for (int i = 0; i < getNumCoordinates(); i += 4)
    {
        int x1 = getCoordinates()[i].first;
        int y1 = getCoordinates()[i].second;
        int x2 = getCoordinates()[i + 2].first;
        int y2 = getCoordinates()[i + 2].second;

        // Check if the point is within the bounding box of the current rectangle
        bool insideBoundingBox = (x >= min(x1, x2)) && (x <= max(x1, x2)) && (y >= min(y1, y2)) && (y <= max(y1, y2));

        // Check if the point is strictly inside the rectangle (excluding the edges)
        if (insideBoundingBox && (x > min(x1, x2)) && (x < max(x1, x2)) && (y > min(y1, y2)) && (y < max(y1, y2)))
        {
            return true;
        }
    }

    return false;
}

bool Cross::isPointOnShape(int x, int y) const
{
    // Iterate over the lines that make up the cross
    for (int i = 0; i < getNumCoordinates(); i += 4)
    {
        int x1 = getCoordinates()[i].first;
        int y1 = getCoordinates()[i].second;
        int x2 = getCoordinates()[i + 2].first;
        int y2 = getCoordinates()[i + 2].second;

        // Check if the point is on the line segment defined by (x1, y1) and (x2, y2)
        if ((x >= min(x1, x2)) && (x <= max(x1, x2)) && (y >= min(y1, y2)) && (y <= max(y1, y2)))
        {
            // Check if the point is on the edge (considering a width of 1 unit)
            if ((x == x1 || x == x2) && (y > min(y1, y2) - 1 && y < max(y1, y2) + 1) ||
                (y == y1 || y == y2) && (x > min(x1, x2) - 1 && x < max(x1, x2) + 1))
            {
                return true;
            }
        }
    }

    return false;
}

string Cross::toString() const
{
    stringstream ss;
    ss << ShapeTwoD::toString(); // Call the parent toString function
    int counts = 0;
    for (const auto &coord : coordinates)
    {
        ss << "Point [" << counts << "] : " << "(" << coord.first << ", " << coord.second << ")\n";
        counts++;
    }

    return ss.str();
}

int Cross::getNumCoordinates() const
{
    return numCoordinates;
}
