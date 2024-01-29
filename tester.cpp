#include <iostream>
#include <string>

using namespace std;

// Parent class
class Shape 
{
    protected:
        string name;

    public:
        virtual void print() = 0; // Pure virtual function. Means all child must have this print() too
        virtual ~Shape() {}        // Add a virtual destructor for proper cleanup
};

// Child class Circle
class Circle : public Shape 
{
    protected:
        int radius; // Change the data type to int for radius

    public:
        // radius constructor
        Circle(int r) : radius(r) {}

        void print() override 
        {
            cout << "Circle with radius " << radius << endl;
        }
};

// Child class Polygon
class Polygon : public Shape 
{
    protected:
        int vertices;

    public:
        Polygon(int v) : vertices(v) {}

        void setVertices(int v) 
        {
            vertices = v;
        }

        void print() override 
        {
            cout << "Polygon with " << vertices << " vertices" << endl;
        }
};

int main() 
{
    const int arraySize = 99;

    // Create instances of Circle and Polygon
    Circle c1(5);
    Polygon p1(4);

    // Create an array of Shape pointers and add instances
    Shape* shapes[arraySize];
    shapes[0] = &c1;
    shapes[1] = &p1;

    // Print information about each shape in the array
    for (int i = 0; i < arraySize; ++i) 
    {
        if (shapes[i] != nullptr) {
            shapes[i]->print();
        }
    }

    return 0;
}
