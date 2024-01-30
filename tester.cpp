#include <iostream>
#include <sstream> 
#include <cmath>   
#include <string>
#include <vector>  

using namespace std;

// Parent class
class Shape
{
    protected:
        string name;
        bool containsWarpSpace;
        vector<pair<int, int>> coordinates;

    public:
        virtual void print() = 0; 
        virtual double computeArea() const = 0; 
        virtual string toString() const = 0;
        virtual bool isPointInShape(int x, int y) const = 0; 
        virtual bool isPointOnShape(int x, int y) const = 0;
        virtual int getNumCoordinates() const = 0; 
        virtual ~Shape() {} // Virtual destructor

        // Getters and setters for name, containsWarpSpace, and coordinates
        string getName() const { return name; }
        void setName(const string &newName) { name = newName; }
        bool getContainsWarpSpace() const { return containsWarpSpace; }
        void setContainsWarpSpace(bool warpSpace) { containsWarpSpace = warpSpace; }
        const vector<pair<int, int>>& getCoordinates() const { return coordinates; }
        void setCoordinates(const vector<pair<int, int>>& newCoordinates) { coordinates = newCoordinates; }
};

// Child class Circle
class Circle : public Shape
{
    protected:
        int radius;
        int numCoordinates = 1; 

    public:
        // Radius constructor
        Circle(int r) : radius(r) 
        {
            // Circles have 1 coordinate, which is the center
            coordinates.push_back({0, 0}); // Placeholder coordinates
        }

        void print() override
        {
            cout << "Circle with radius " << radius << ", named " << getName() << endl;
        }

        double computeArea() const override
        {
            return 5*5; // Placeholder logic
        }

        bool isPointInShape(int x, int y) const override
        {
            // Placeholder logic
            return true;
        }

        bool isPointOnShape(int x, int y) const override
        {
            // Placeholder logic
            return true;
        }

        string toString() const override
        {
            stringstream ss;
            ss << "Circle: Name = " << getName() << ", Radius = " << radius << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");

            // Add coordinates information
            ss << ", Coordinates = ";
            for (const auto& coord : getCoordinates()) {
                ss << "(" << coord.first << ", " << coord.second << ") ";
            }

            return ss.str();
        }

        int getNumCoordinates() const override
        {
            return numCoordinates;
        }
};

// Child class Square
class Square : public Shape
{
    protected:
        int numCoordinates = 4;

    public:
        // Default constructor
        Square() 
        {
            // Squares have 4 coordinates
            coordinates = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; // Placeholder coordinates
        }

        void print() override
        {
            cout << "Square named " << getName() << endl;
        }

        double computeArea() const override
        {
            return 1.0;
        }

        bool isPointInShape(int x, int y) const override
        {
            // Placeholder logic
            return true;
        }

        bool isPointOnShape(int x, int y) const override
        {
            // Placeholder logic
            return true;
        }

        string toString() const override
        {
            stringstream ss;
            ss << "Square: Name = " << getName() << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");

            // Add coordinates information
            ss << ", Coordinates = ";
            for (const auto& coord : getCoordinates()) {
                ss << "(" << coord.first << ", " << coord.second << ") ";
            }

            return ss.str();
        }

        int getNumCoordinates() const override
        {
            return numCoordinates;
        }
};

// Child class Rectangle
class Rectangle : public Shape
{
    protected:
        int numCoordinates = 4;

    public:
        // Default constructor
        Rectangle() {
            // Rectangles have 4 coordinates
            coordinates = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; // Placeholder coordinates
        }

        void print() override
        {
            cout << "Rectangle named " << getName() << endl;
        }

        double computeArea() const override
        {
            return 1.0;
        }

        bool isPointInShape(int x, int y) const override
        {
            // Placeholder logic
            return true;
        }

        bool isPointOnShape(int x, int y) const override
        {
            // Placeholder logic
            return true;
        }

        string toString() const override
        {
            stringstream ss;
            ss << "Rectangle: Name = " << getName() << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");

            // Add coordinates information
            ss << ", Coordinates = ";
            for (const auto& coord : getCoordinates()) {
                ss << "(" << coord.first << ", " << coord.second << ") ";
            }

            return ss.str();
        }

        int getNumCoordinates() const override
        {
            return numCoordinates;
        }
};

// Child class Cross
class Cross : public Shape
{
    protected:
        int numCoordinates = 12;

    public:
        // Default constructor
        Cross() 
        {
            // Crosses have 12 coordinates
            coordinates = {
                {0, -1}, {0, 0}, {0, 1},
                {-1, 0}, {0, 0}, {1, 0},
                {-1, -1}, {0, 0}, {1, 1},
                {-1, 1}, {0, 0}, {1, -1}
            }; // Placeholder coordinates
        }

        void print() override
        {
            cout << "Cross named " << getName() << endl;
        }

        double computeArea() const override
        {
            return 5 * 8; // Placeholder logic
        }

        bool isPointInShape(int x, int y) const override
        {
            // Placeholder logic
            return true;
        }

        bool isPointOnShape(int x, int y) const override
        {
            // Placeholder logic
            return true;
        }

        string toString() const override
        {
            stringstream ss;
            ss << "Cross: Name = " << getName() << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");

            // Add coordinates information
            ss << ", Coordinates = ";
            for (const auto& coord : getCoordinates()) {
                ss << "(" << coord.first << ", " << coord.second << ") ";
            }

            return ss.str();
        }

        int getNumCoordinates() const override
        {
            return numCoordinates;
        }
};

int main()
{
    const int arraySize = 99;

    // Create instances of Circle, Square, Rectangle, and Cross
    Circle c1(5);
    Square s1;
    Rectangle r1;
    Cross cross1;

    // Set names, containsWarpSpace, and coordinates for the shapes
    c1.setName("C1");
    c1.setContainsWarpSpace(true);

    s1.setName("S1");
    s1.setContainsWarpSpace(false);

    r1.setName("R1");
    r1.setContainsWarpSpace(true);

    cross1.setName("Cross1");
    cross1.setContainsWarpSpace(false);

    // Create an array of Shape pointers using new
    Shape **shapes = new Shape *[arraySize];

    // Initialize all elements to nullptr
    for (int i = 0; i < arraySize; ++i)
    {
        shapes[i] = nullptr;
    }

    // Assign instances to the array
    shapes[0] = &c1;
    shapes[1] = &s1;
    shapes[2] = &r1;
    shapes[3] = &cross1;

    // Print information about each shape in the array
    for (int i = 0; i < arraySize; ++i)
    {
        if (shapes[i] != nullptr)
        {
            cout << shapes[i]->toString() << endl;

            // Check if the point (2, 2) is in or on the shape
            cout << "Is point (2, 2) in the shape? " << (shapes[i]->isPointInShape(2, 2) ? "Yes" : "No") << endl;
            cout << "Is point (2, 2) on the shape? " << (shapes[i]->isPointOnShape(2, 2) ? "Yes" : "No") << endl;

            // Print the number of coordinates
            cout << "Number of coordinates: " << shapes[i]->getNumCoordinates() << endl;
        }
    }

    // Clean up memory using delete[]
    delete[] shapes;

    return 0;
}
