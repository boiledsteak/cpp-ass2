/*============================

Timothy Mah C++ module assignment 2
18 Jan 2024

due 8 Feb 2024

=============================*/

#include <limits>
#include <iostream>
#include <sstream> 
#include <cmath>   
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// SEE SLIDES S4F
// Parent class
class ShapeTwoD
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
        virtual ~ShapeTwoD() {} // Virtual destructor

        // Getters and setters for name, containsWarpSpace, and coordinates
        string getName() const { return name; }
        void setName(const string &newName) { name = newName; }
        bool getContainsWarpSpace() const { return containsWarpSpace; }
        void setContainsWarpSpace(bool warpSpace) { containsWarpSpace = warpSpace; }
        const vector<pair<int, int>>& getCoordinates() const { return coordinates; }
        //when setting coordinates, number of coordinates must match each shape's required number
        void setCoordinates(const vector<pair<int, int>> &newCoordinates, int numCoordinates)
        {
                coordinates.insert(coordinates.end(), newCoordinates.begin(), newCoordinates.end());
        }
};

// Child class Circle
class Circle : public ShapeTwoD
{
    protected:
        int radius;
        int numCoordinates = 1; 

    public:
        // Default constructor
        Circle() {}

        void print() override
        {
            cout << "Circle with radius " << radius << ", named " << getName() << endl;
        }

        
        void setRadius(int r)
        {
            radius = r;
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
            ss << "Name = " << getName() << ", Radius = " << radius << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");

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
class Square : public ShapeTwoD
{
    protected:
        int numCoordinates = 4;

    public:
        // Default constructor
        Square() {}

        void print() override
        {
            cout << "Square named " << getName() << endl;
        }

        double computeArea() const override
        {
            // Assuming the input coordinates are in any order, find the min and max coordinates
            int minX = numeric_limits<int>::max();
            int minY = numeric_limits<int>::max();
            int maxX = numeric_limits<int>::min();
            int maxY = numeric_limits<int>::min();

            for (const auto& coord : getCoordinates())
            {
                minX = min(minX, coord.first);
                minY = min(minY, coord.second);
                maxX = max(maxX, coord.first);
                maxY = max(maxY, coord.second);
            }

            // Calculate and return the area using the min and max coordinates
            int sideLength = max(maxX - minX, maxY - minY);
            return static_cast<double>(sideLength * sideLength);
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
            ss << "Name = " << getName() << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");

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
class Rectangle : public ShapeTwoD
{
    protected:
        int numCoordinates = 4;

    public:
        // Default constructor
        Rectangle() {}

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
            ss << "Name = " << getName() << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");

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
class Cross : public ShapeTwoD
{
    protected:
        int numCoordinates = 12;

    public:
        // Default constructor
        Cross() {}

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
            ss << "Name = " << getName() << ", ContainsWarpSpace = " << (getContainsWarpSpace() ? "true" : "false");

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

void menuprinter()
{
    cout << "\n\n\n";
    cout << "Student ID:" << "\t10258663\n";
    cout << "Student name:" << "\tTimothy Mah\n";
    cout << "------------------------------------------------------\n";
    cout << "Welcome to Assignment 2 program!\n\n";
    cout << "1)" << "\tInput sensor data\n"; //the input coords will always be adjacent and clockwise
    cout << "2)" << "\tCompute area (for all records)\n"; // should apply polymorphism and dynamic binding. There should  only be one array. Not one array for each shape
    cout << "3)" << "\tPrint shapes report\n"; // there may be shapes where there's no point in shape // when printing points on shape, skip the points that user has input // when printing circle on shape, only need to print the top bottom left right edges // to find inside point of circle, find the surrounding box of the circle 
    cout << "4)" << "\tSort shape data\n"; // sort by special type and area.
    // ws biggest
    // ws smallest
    // ns biggest
    // ns smallest
    cout << "5)" << "\tExit\n";
    cout << "\n\nTell me what you want!\n\n";
}


int main()
{
    int progflow = 1;
    int menuchoice = 0;
    string invalidinp = "\nSorry I do not understand :( Please try again!\n\n";

    const int arraySize = 99;
    // Create an array of Shape pointers using new
    vector<ShapeTwoD*> shapes;


    while (progflow == 1)
    {
        menuprinter();
        // input validation
        while (!(cin >> menuchoice) || cin.peek() != '\n') 
        {
            cout << invalidinp;
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            menuprinter();
        }

        switch (menuchoice)
        {
            case 1:
            {
                string shape;
                string specialtype;
                int x;
                int y;
                int radius;
                

                cout << ">>>>>>>>>>>>\t"<< "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
                cout << "[Input sensor data]\n";
                
                // validate name of shape
                while (true)
                {
                    cout << "Please enter name of the shape:\t";
                    getline(cin >> ws, shape); //ignore whitespace
                    // case insensitive user input
                    transform(shape.begin(), shape.end(), shape.begin(), ::tolower);
                    if (shape == "square" || shape == "rectangle" || shape == "circle" || shape == "cross")
                    {
                        cout << "yep! the shape: " << shape << " is correct!\n";
                        break;
                    }
                    else
                    {
                        cout << invalidinp;
                        cin.sync(); // Clear the input buffer
                        cin.clear();  // Clear the error flag
                    }
                    
                }
                
                cout << "\n\n";
                
                // validate input
                while (true)
                {
                    cout << "Please enter special type: ";
                    getline(cin >> ws, specialtype); //ignore whitespace
                    // case insensitive user input
                    transform(specialtype.begin(), specialtype.end(), specialtype.begin(), ::tolower);
                    if (specialtype == "ws" || specialtype == "ns")
                    {
                        //TODO some logic with user input special type WS
                        cout << "yep! the special type: " << specialtype << " is correct!\n";
                        break;
                    }
                    else
                    {
                        cout << invalidinp;
                        cin.sync();
                        cin.clear();  
                    }

                }
                cout << "\n\n";
                // if shape is circle
                if (shape == "circle")
                {
                    // Create Circle object and set its properties
                    Circle* circle = new Circle();
                    circle->setName(shape);
                    circle->setContainsWarpSpace(specialtype == "ws");

                    // set the radius of the circle
                    cout << "Please enter the radius of the circle: \n";
                    while (true)
                    {
                        cin >> radius;
                        // Validate radius
                        if (cin.fail() || radius <= 0 || cin.peek() != '\n')
                        {
                            cin.clear(); 
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << invalidinp;
                            cout << "Please enter the radius of the circle: \n";
                        }
                        else
                        {
                            break;
                        }
                    }
                    circle->setRadius(radius);

                    // set the center coordinates of the circle
                    cout << "Please enter x coordinate of center: ";
                    while (true)
                    {
                        cin >> x;
                        // Validate x coordinate as integer
                        if (cin.fail() || cin.peek() != '\n')
                        {
                            cin.clear();  // Clear the error flag
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                            cout << invalidinp;
                            cout << "Please enter x coordinate of center: ";
                        }
                        else
                        {
                            break;
                        }
                    }

                    cout << "Please enter y coordinate of center: ";
                    while (true)
                    {
                        cin >> y;
                        // Validate x coordinate as integer
                        if (cin.fail() || cin.peek() != '\n')
                        {
                            cin.clear();  // Clear the error flag
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                            cout << invalidinp;
                            cout << "Please enter y coordinate of center: ";
                        }
                        else
                        {
                            break;
                        }
                    }

                    // Set the center coordinates for the circle
                    circle->setCoordinates({{x, y}}, circle->getNumCoordinates());
                     
                    // Add the created Circle object to the vector
                    shapes.push_back(circle);
                }

                else if (shape == "square")
                {
                    // Create Square object and set its properties
                    Square* square = new Square();
                    square->setName(shape);
                    square->setContainsWarpSpace(specialtype == "ws");

                    for (int i = 0; i < square->getNumCoordinates(); ++i)
                    {
                        // set the coordinates of the square
                        cout << "Please enter x coordinate "<< i+1 << " for square: ";
                        while (true)
                        {
                            cin >> x;
                            // Validate x coordinate as integer
                            if (cin.fail() || cin.peek() != '\n')
                            {
                                cin.clear();  // Clear the error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                                cout << invalidinp;
                                cout << "Please enter x coordinate "<< i+1 << " for square: ";
                            }
                            else
                            {
                                break;
                            }
                        }

                        cout << "Please enter y coordinate "<< i+1 << " for square: ";
                        while (true)
                        {
                            cin >> y;
                            // Validate x coordinate as integer
                            if (cin.fail() || cin.peek() != '\n')
                            {
                                cin.clear();  // Clear the error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                                cout << invalidinp;
                                cout << "Please enter y coordinate "<< i+1 << " for square: ";
                            }
                            else
                            {
                                break;
                            }
                        }

                        // Add coordinates to the vector for the square
                        square->setCoordinates({{x, y}}, square->getNumCoordinates());
                    }

                    // Add the created Square object to the vector
                    shapes.push_back(square);

                }
                else if (shape == "rectangle")
                {
                    // Create rectangle object and set its properties
                    Rectangle* rectangle = new Rectangle();
                    rectangle->setName(shape);
                    rectangle->setContainsWarpSpace(specialtype == "ws");

                    for (int i = 0; i < rectangle->getNumCoordinates(); ++i)
                    {
                        // set the coordinates of the rectangle
                        cout << "Please enter x coordinate "<< i+1 << " for rectangle: ";
                        while (true)
                        {
                            cin >> x;
                            // Validate x coordinate as integer
                            if (cin.fail() || cin.peek() != '\n')
                            {
                                cin.clear();  // Clear the error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                                cout << invalidinp;
                                cout << "Please enter x coordinate "<< i+1 << " for rectangle: ";
                            }
                            else
                            {
                                break;
                            }
                        }

                        cout << "Please enter y coordinate "<< i+1 << " for rectangle: ";
                        while (true)
                        {
                            cin >> y;
                            // Validate x coordinate as integer
                            if (cin.fail() || cin.peek() != '\n')
                            {
                                cin.clear();  // Clear the error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                                cout << invalidinp;
                                cout << "Please enter y coordinate "<< i+1 << " for rectangle: ";
                            }
                            else
                            {
                                break;
                            }
                        }

                        // Add coordinates to the vector for the rectangle
                        rectangle->setCoordinates({{x, y}}, rectangle->getNumCoordinates());
                    }

                    // Add the created rectangle object to the vector
                    shapes.push_back(rectangle);
                }

                else if (shape == "cross")
                {
                    // Create cross object and set its properties
                    Cross* cross = new Cross();
                    cross->setName(shape);
                    cross->setContainsWarpSpace(specialtype == "ws");

                    for (int i = 0; i < cross->getNumCoordinates(); ++i)
                    {
                        // set the coordinates of the cross
                        cout << "Please enter x coordinate "<< i+1 << " for cross: ";
                        while (true)
                        {
                            cin >> x;
                            // Validate x coordinate as integer
                            if (cin.fail() || cin.peek() != '\n')
                            {
                                cin.clear();  // Clear the error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                                cout << invalidinp;
                                cout << "Please enter x coordinate "<< i+1 << " for cross: ";
                            }
                            else
                            {
                                break;
                            }
                        }

                        cout << "Please enter y coordinate "<< i+1 << " for cross: ";
                        while (true)
                        {
                            cin >> y;
                            // Validate x coordinate as integer
                            if (cin.fail() || cin.peek() != '\n')
                            {
                                cin.clear();  // Clear the error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                                cout << invalidinp;
                                cout << "Please enter y coordinate "<< i+1 << " for cross: ";
                            }
                            else
                            {
                                break;
                            }
                        }

                        // Add coordinates to the vector for the cross
                        cross->setCoordinates({{x, y}}, cross->getNumCoordinates());
                    }

                    // Add the created Square object to the vector
                    shapes.push_back(cross);
                }

            }
            break;
            case 2:
            {
                cout << "Computing and printing area for all shapes:\n";
                for (const ShapeTwoD* shape : shapes)
                {
                    cout << "Area of " << shape->getName() << ": " << shape->computeArea() << endl;
                }
            }
            break;
            case 3:
            {
                cout << "Printing values stored in all shapes:\n";
                for (const ShapeTwoD* shape : shapes)
                {
                    cout << shape->toString() << endl;
                }
            }
            break;


            case 4:
            {

            }
            break;
            case 5:
            {
                progflow = 0;
            }
            break;
            default:
                cout << "\nWe don't have that option :( Please try again...\n\n";
            break;
        }
    }
    // Clean up memory using delete
    for (ShapeTwoD* shape : shapes)
    {
        delete shape;
    }
    
    return 0;
}
