#ifndef CROSS_H
#define CROSS_H

#include "shapetwod.h"
#include <iostream>
#include <vector>

class Cross : public ShapeTwoD
{
    protected:
        int numCoordinates = 12;

    public:
        // Default constructor
        Cross();

        double computeArea() const override;

        bool isPointInShape(int x, int y) const override;

        bool isPointOnShape(int x, int y) const override;

        string toString() const override;

        int getNumCoordinates() const override;
};

#endif
