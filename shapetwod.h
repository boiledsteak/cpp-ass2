#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class ShapeTwoD
{
    protected:
        string name;
        bool containsWarpSpace;
        vector<pair<int, int>> coordinates;

    public:
        virtual double computeArea() const = 0;
        virtual bool isPointInShape(int x, int y) const = 0;
        virtual bool isPointOnShape(int x, int y) const = 0;
        virtual int getNumCoordinates() const = 0;
        virtual ~ShapeTwoD() = default; // Virtual destructor
        virtual string toString() const
        {
            stringstream ss;
            ss << "name:\t" << name << endl;
            ss << "special type:\t" << (containsWarpSpace ? "WS" : "NS") << endl;
            ss << "area: " << computeArea() << " units square\n";
            ss << "Vertices:\n";

            return ss.str();
        }

        // Getters and setters for name, containsWarpSpace, and coordinates
        string getName() const { return name; }
        void setName(const string &newName) { name = newName; }
        bool getContainsWarpSpace() const { return containsWarpSpace; }
        void setContainsWarpSpace(bool warpSpace) { containsWarpSpace = warpSpace; }
        const vector<pair<int, int>> &getCoordinates() const { return coordinates; }
        void setCoordinates(const vector<pair<int, int>> &newCoordinates, int numCoordinates)
        {
            // accumulate all shape objects to coordinates vector
            coordinates.insert(coordinates.end(), newCoordinates.begin(), newCoordinates.end());
        }
};

#endif
