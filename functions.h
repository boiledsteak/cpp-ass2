#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "shapetwod.h"

void menuprinter();
void smallmenuprinter();
bool compareShapesByArea(const ShapeTwoD* a, const ShapeTwoD* b, bool ascending);
void printCoordinatesInfo(const ShapeTwoD* shape, int& minX, int& minY, int& maxX, int& maxY, bool& hasPointsInside, bool& hasPointsOnShape);
void printShapeInfo(const ShapeTwoD* shape, int counter);
bool compareShapes(const ShapeTwoD* a, const ShapeTwoD* b);

#endif
