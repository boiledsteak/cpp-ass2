#ifndef SQUARE_H
#define SQUARE_H

#include "shapetwod.h"

// Child class Square
class Square : public ShapeTwoD
{
    protected:
        int numCoordinates = 4;

    public:
        // Default constructor
        Square();

        double computeArea() const override;

        bool isPointInShape(int x, int y) const override;

        bool isPointOnShape(int x, int y) const override;

        string toString() const override;

        int getNumCoordinates() const override;
};

#endif
