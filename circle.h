#ifndef CIRCLE_H
#define CIRCLE_H

#include "shapetwod.h" // Include the parent

class Circle : public ShapeTwoD
{
protected:
    int radius;
    int numCoordinates = 1;

public:
    // Default constructor
    Circle() {}

    void setRadius(int r);

    int getRadius() const;

    double computeArea() const override;

    bool isPointInShape(int x, int y) const override;

    bool isPointOnShape(int x, int y) const override;

    string toString() const override;

    int getNumCoordinates() const override;
};

#endif
