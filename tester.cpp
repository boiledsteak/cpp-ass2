#include <iostream>
#include <sstream> // For stringstream
#include <cmath>   // For M_PI
#include <string>

using namespace std;

// Parent class
class Shape
{
protected:
    string name;
    bool containsWarpSpace;

public:
    virtual void print() = 0; // Pure virtual function
    virtual double computeArea() const = 0; // Virtual function for area
    virtual string toString() const = 0; // Virtual function for string representation
    virtual bool isPointInShape(int x, int y) const = 0; // Virtual function for checking if a point is in the shape
    virtual bool isPointOnShape(int x, int y) const = 0; // Virtual function for checking if a point is on the shape
    virtual ~Shape() {} // Virtual destructor

    // Getters and setters for name and containsWarpSpace
    string getName() const { return name; }
    void setName(const string &newName) { name = newName; }
    bool getContainsWarpSpace() const { return containsWarpSpace; }
    void setContainsWarpSpace(bool warpSpace) { containsWarpSpace = warpSpace; }
};

// Child class Circle
class Circle : public Shape
{
protected:
    int radius;

public:
    // Radius constructor
    Circle(int r) : radius(r) {}

    void print() override
    {
        cout << "Circle with radius " << radius << ", named " << getName() << endl;
    }

    double computeArea() const override
    {
        return 5*5; //placeholder logic
    }

    bool isPointInShape(int x, int y) const override
    {
        
        return true; //placeholder logic
    }

    bool isPointOnShape(int x, int y) const override
    {
        
        return true; //placeholder logic
    }

    string toString() const override
    {
        stringstream ss;
        ss << "Circle: Name = " << getName() << ", Radius = " << radius << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");
        return ss.str();
    }
};

// Child class Square
class Square : public Shape
{
protected:
    int side;

public:
    // Side constructor
    Square(int s) : side(s) {}

    void print() override
    {
        cout << "Square with side " << side << ", named " << getName() << endl;
    }

    double computeArea() const override
    {
        return side * side;
    }

    bool isPointInShape(int x, int y) const override
    {
        
        return true; //placeholder logic
    }

    bool isPointOnShape(int x, int y) const override
    {
        
        return true; //placeholder logic
    }

    string toString() const override
    {
        stringstream ss;
        ss << "Square: Name = " << getName() << ", Side = " << side << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");
        return ss.str();
    }
};

// Child class Rectangle
class Rectangle : public Shape
{
protected:
    int length;
    int width;

public:
    // Length and width constructor
    Rectangle(int l, int w) : length(l), width(w) {}

    void print() override
    {
        cout << "Rectangle with length " << length << " and width " << width << ", named " << getName() << endl;
    }

    double computeArea() const override
    {
        return length * width;
    }

    bool isPointInShape(int x, int y) const override
    {
        
        return true; //placeholder logic
    }

    bool isPointOnShape(int x, int y) const override
    {
        
        return true; //placeholder logic
    }

    string toString() const override
    {
        stringstream ss;
        ss << "Rectangle: Name = " << getName() << ", Length = " << length << ", Width = " << width << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");
        return ss.str();
    }
};

// Child class Cross
class Cross : public Shape
{
protected:
    int armLength;

public:
    // Arm length constructor
    Cross(int a) : armLength(a) {}

    void print() override
    {
        cout << "Cross with arm length " << armLength << ", named " << getName() << endl;
    }

    double computeArea() const override
    {
        
        return 5*8; //placeholder logic 
    }

    bool isPointInShape(int x, int y) const override
    {
       
        return true; //placeholder logic
    }

    bool isPointOnShape(int x, int y) const override
    {
        
        return true; //placeholder logic
    }

    string toString() const override
    {
        stringstream ss;
        ss << "Cross: Name = " << getName() << ", Arm Length = " << armLength << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");
        return ss.str();
    }
};

int main()
{
    const int arraySize = 99;

    // Create instances of Circle, Square, Rectangle, and Cross
    Circle c1(5);
    Square s1(8);
    Rectangle r1(6, 10);
    Cross cross1(7);

    // Set names and containsWarpSpace for the shapes
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
        }
    }

    // Clean up memory using delete[]
    delete[] shapes;

    return 0;
}
