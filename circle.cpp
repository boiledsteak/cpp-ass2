#include "circle.h"
#include <cmath> 
#include <sstream>

void Circle::setRadius(int r)
{
    radius = r;
}

int Circle::getRadius() const
{
    return radius;
}

double Circle::computeArea() const
{
    return M_PI * radius * radius;
}

bool Circle::isPointInShape(int x, int y) const
{
    int centerX = getCoordinates()[0].first; // Assuming the first coordinate is the center for the circle
    int centerY = getCoordinates()[0].second;

    // Check if the distance from the point (x, y) to the center is less than the radius
    bool insideCircle = pow(x - centerX, 2) + pow(y - centerY, 2) < pow(radius, 2);

    // Exclude the center coordinate and return the result
    return insideCircle && !(x == centerX && y == centerY);
}

bool Circle::isPointOnShape(int x, int y) const
{
    int centerX = getCoordinates()[0].first; // Assuming the first coordinate is the center for the circle
    int centerY = getCoordinates()[0].second;

    // Check if the point (x, y) is on the north, south, east, or west points of the circle
    return (x == centerX && (y == centerY + radius || y == centerY - radius)) ||
           (y == centerY && (x == centerX + radius || x == centerX - radius));
}

string Circle::toString() const
{
    stringstream ss;
    ss << ShapeTwoD::toString(); // Call the parent class toString function
    ss << "Radius:\t" << radius << "\n";
    ss << "Centre coordinate:\t";
    for (const auto &coord : getCoordinates())
    {
        ss << "(" << coord.first << ", " << coord.second << ") ";
    }

    return ss.str();
}

int Circle::getNumCoordinates() const
{
    return numCoordinates;
}
