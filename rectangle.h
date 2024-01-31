#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shapetwod.h"
#include <iostream>
#include <vector>

class Rectangle : public ShapeTwoD
{
    protected:
        int numCoordinates = 4;

    public:
        // Default constructor
        Rectangle();

        double computeArea() const override;

        bool isPointInShape(int x, int y) const override;

        bool isPointOnShape(int x, int y) const override;

        string toString() const override;

        int getNumCoordinates() const override;
};

#endif // RECTANGLE_H
