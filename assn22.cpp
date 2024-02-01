/*============================

Timothy Mah C++ module assignment 2
18 Jan 2024

due 8 Feb 2024

the one with all functions all in one
no file encapsulation

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
        virtual double computeArea() const = 0; 
        virtual bool isPointInShape(int x, int y) const = 0; 
        virtual bool isPointOnShape(int x, int y) const = 0;
        virtual int getNumCoordinates() const = 0; 
        virtual ~ShapeTwoD() {} // Virtual destructor
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
        const vector<pair<int, int>>& getCoordinates() const { return coordinates; }
        void setCoordinates(const vector<pair<int, int>> &newCoordinates, int numCoordinates)
        {
            // accumulate all shape objects to coordinates vector
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
        
        void setRadius(int r)
        {
            radius = r;
        }

        int getRadius() const
        {
            return radius;
        }

        double computeArea() const override
        {
            return 3.142 * radius * radius; // Placeholder logic
        }

        bool isPointInShape(int x, int y) const override
        {
            int centerX = getCoordinates()[0].first; // Assuming the first coordinate is the center for the circle
            int centerY = getCoordinates()[0].second;

            // Check if the distance from the point (x, y) to the center is less than the radius
            bool insideCircle = pow(x - centerX, 2) + pow(y - centerY, 2) < pow(radius, 2);

            // Exclude the center coordinate and return the result
            return insideCircle && !(x == centerX && y == centerY);
        }


        bool isPointOnShape(int x, int y) const override
        {
            int centerX = getCoordinates()[0].first; // Assuming the first coordinate is the center for the circle
            int centerY = getCoordinates()[0].second;

            // Check if the point (x, y) is on the north, south, east, or west points of the circle
            return (x == centerX && (y == centerY + radius || y == centerY - radius)) ||
                (y == centerY && (x == centerX + radius || x == centerX - radius));
        }


        string toString() const override
        {
            stringstream ss;
            ss << ShapeTwoD::toString(); // Call the base class toString function
            ss << "Radius:\t" << radius << "\n";
            ss << "Centre coordinate:\t";
            for (const auto &coord : coordinates)
            {
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

        double computeArea() const override
        {
            // Assuming the input coordinates are in any order, find the min and max coordinates
            int minX = numeric_limits<int>::max();
            int minY = numeric_limits<int>::max();
            int maxX = numeric_limits<int>::min();
            int maxY = numeric_limits<int>::min();

            for (const auto &coord : getCoordinates())
            {
                minX = min(minX, coord.first);
                minY = min(minY, coord.second);
                maxX = max(maxX, coord.first);
                maxY = max(maxY, coord.second);
            }

            // Calculate and return the area using the min and max coordinates
            int length = maxX - minX;
            int width = maxY - minY;
            return static_cast<double>(length * width);
        }

        bool isPointInShape(int x, int y) const override
        {
            // Assuming the input coordinates are in any order, find the min and max coordinates
            int minX = numeric_limits<int>::max();
            int minY = numeric_limits<int>::max();
            int maxX = numeric_limits<int>::min();
            int maxY = numeric_limits<int>::min();

            for (const auto &coord : getCoordinates())
            {
                minX = min(minX, coord.first);
                minY = min(minY, coord.second);
                maxX = max(maxX, coord.first);
                maxY = max(maxY, coord.second);
            }

            // Check if the point is strictly within the rectangle (excluding the edges)
            bool insideRectangle = (x > minX) && (x < maxX) && (y > minY) && (y < maxY);

            return insideRectangle;
        }

        bool isPointOnShape(int x, int y) const override
        {
            // Iterate over each pair of consecutive coordinates to check if the point is on any edge
            for (int i = 0; i < numCoordinates; ++i)
            {
                int x1 = getCoordinates()[i].first;
                int y1 = getCoordinates()[i].second;
                int x2 = getCoordinates()[(i + 1) % numCoordinates].first; // Wrap around to the first coordinate for the last edge
                int y2 = getCoordinates()[(i + 1) % numCoordinates].second;

                // Check if the point is on the line segment defined by (x1, y1) and (x2, y2)
                if ((x >= min(x1, x2) && x <= max(x1, x2)) && (y >= min(y1, y2) && y <= max(y1, y2)))
                {
                    // Check if the point is on the edge (excluding the corners)
                    if ((x == x1 || x == x2) && (y > min(y1, y2) && y < max(y1, y2)) ||
                        (y == y1 || y == y2) && (x > min(x1, x2) && x < max(x1, x2)))
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        string toString() const override
        {
            stringstream ss;
            ss << ShapeTwoD::toString(); // Call the base class toString function
            int counts=0;
            for (const auto &coord : coordinates)
            {
                ss << "Point ["<< counts << "] : " << "(" << coord.first << ", " << coord.second << ")\n";
                counts++;
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

        double computeArea() const override
        {
            // Assuming the input coordinates are in any order, find the min and max coordinates
            int minX = numeric_limits<int>::max();
            int minY = numeric_limits<int>::max();
            int maxX = numeric_limits<int>::min();
            int maxY = numeric_limits<int>::min();

            for (const auto &coord : getCoordinates())
            {
                minX = min(minX, coord.first);
                minY = min(minY, coord.second);
                maxX = max(maxX, coord.first);
                maxY = max(maxY, coord.second);
            }

            // Calculate and return the area using the min and max coordinates
            int length = maxX - minX;
            int width = maxY - minY;
            return static_cast<double>(length * width);
        }

        bool isPointInShape(int x, int y) const override
        {
            // Assuming the input coordinates are in any order, find the min and max coordinates
            int minX = numeric_limits<int>::max();
            int minY = numeric_limits<int>::max();
            int maxX = numeric_limits<int>::min();
            int maxY = numeric_limits<int>::min();

            for (const auto &coord : getCoordinates())
            {
                minX = min(minX, coord.first);
                minY = min(minY, coord.second);
                maxX = max(maxX, coord.first);
                maxY = max(maxY, coord.second);
            }

            // Check if the point is strictly within the rectangle (excluding the edges)
            bool insideRectangle = (x > minX) && (x < maxX) && (y > minY) && (y < maxY);

            return insideRectangle;
        }

        bool isPointOnShape(int x, int y) const override
        {
            // Iterate over each pair of consecutive coordinates to check if the point is on any edge
            for (int i = 0; i < numCoordinates; ++i)
            {
                int x1 = getCoordinates()[i].first;
                int y1 = getCoordinates()[i].second;
                int x2 = getCoordinates()[(i + 1) % numCoordinates].first; // Wrap around to the first coordinate for the last edge
                int y2 = getCoordinates()[(i + 1) % numCoordinates].second;

                // Check if the point is on the line segment defined by (x1, y1) and (x2, y2)
                if ((x >= min(x1, x2) && x <= max(x1, x2)) && (y >= min(y1, y2) && y <= max(y1, y2)))
                {
                    // Check if the point is on the edge (excluding the corners)
                    if ((x == x1 || x == x2) && (y > min(y1, y2) && y < max(y1, y2)) ||
                        (y == y1 || y == y2) && (x > min(x1, x2) && x < max(x1, x2)))
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        string toString() const override
        {
            stringstream ss;
            ss << ShapeTwoD::toString(); // Call the base class toString function
            int counts=0;
            for (const auto &coord : coordinates)
            {
                ss << "Point ["<< counts << "] : " << "(" << coord.first << ", " << coord.second << ")\n";
                counts++;
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

        double computeArea() const override
        {
            double rectangleArea = 0.0;
            vector<pair<int, int>> sortedCoordinates = coordinates;
            sort(sortedCoordinates.begin(), sortedCoordinates.end());

            for (int i = 0; i < numCoordinates; i += 4)
            {
                int x1 = sortedCoordinates[i].first;
                int y1 = sortedCoordinates[i].second;
                int x2 = sortedCoordinates[i + 2].first;
                int y2 = sortedCoordinates[i + 2].second;

                rectangleArea += abs(x2 - x1) * abs(y2 - y1);
            }

            return rectangleArea;
        }


        bool isPointInShape(int x, int y) const override
        {//untested lol
            // Iterate over the rectangles that make up the cross
            for (int i = 0; i < getNumCoordinates(); i += 4)
            {
                int x1 = getCoordinates()[i].first;
                int y1 = getCoordinates()[i].second;
                int x2 = getCoordinates()[i + 2].first;
                int y2 = getCoordinates()[i + 2].second;

                // Check if the point is within the bounding box of the current rectangle
                bool insideBoundingBox = (x >= min(x1, x2)) && (x <= max(x1, x2)) && (y >= min(y1, y2)) && (y <= max(y1, y2));

                // Check if the point is strictly inside the rectangle (excluding the edges)
                if (insideBoundingBox && (x > min(x1, x2)) && (x < max(x1, x2)) && (y > min(y1, y2)) && (y < max(y1, y2)))
                {
                    return true;
                }
            }

            return false;
        }

        bool isPointOnShape(int x, int y) const override
        {
            // Placeholder logic
            return true;
        }

        string toString() const override
        {
            stringstream ss;
            ss << ShapeTwoD::toString(); // Call the base class toString function
            int counts=0;
            for (const auto &coord : coordinates)
            {
                ss << "Point ["<< counts << "] : " << "(" << coord.first << ", " << coord.second << ")\n";
                counts++;
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
    cout << "3)" << "\tPrint shapes report\n"; 
    cout << "4)" << "\tSort shape data\n"; // sort by special type and area.
    // ws biggest
    // ws smallest
    // ns biggest
    // ns smallest
    cout << "5)" << "\tExit\n";
    cout << "\n\nTell me what you want!\n\n";
}

void smallmenuprinter()
{
    cout << "\ta.\tSort by area (ascending)\n";
    cout << "\tb.\tSort by area (descending)\n";
    cout << "\tc.\tSort by special type and area\n";
    cout << "\nPlease select option ('q' to go main menu)\n\n";
}

// false for big to small. true for small to big
bool compareShapesByArea(const ShapeTwoD* a, const ShapeTwoD* b, bool ascending) 
{
    return ascending ? (a->computeArea() < b->computeArea()) : (a->computeArea() > b->computeArea());
}

// Function to print coordinates information
void printCoordinatesInfo(const ShapeTwoD* shape, int& minX, int& minY, int& maxX, int& maxY, bool& hasPointsInside, bool& hasPointsOnShape) 
{
    for (int x = minX; x <= maxX; ++x) 
    {
        for (int y = minY; y <= maxY; ++y) 
        {
            if (shape->isPointOnShape(x, y) && find(shape->getCoordinates().begin(), shape->getCoordinates().end(), make_pair(x, y)) == shape->getCoordinates().end()) 
            {
                cout << "(" << x << ", " << y << ") ";
                hasPointsOnShape = true;
            }
        }
    }

    if (!hasPointsOnShape) 
    {
        cout << " none!";
    }

    cout << "\n";

    cout << "Points within shape:\t";

    for (const auto& coord : shape->getCoordinates()) 
    {
        if (shape->isPointInShape(coord.first, coord.second)) 
        {
            cout << "(" << coord.first << ", " << coord.second << ") ";
            hasPointsInside = true;
            // Update min and max coordinates for the bounding box
            minX = min(minX, coord.first);
            minY = min(minY, coord.second);
            maxX = max(maxX, coord.first);
            maxY = max(maxY, coord.second);
        }
    }

    // Print additional coordinates inside the area that were not input by the user
    for (int x = minX; x <= maxX; ++x) 
    {
        for (int y = minY; y <= maxY; ++y) 
        {
            if (shape->isPointInShape(x, y) && find(shape->getCoordinates().begin(), shape->getCoordinates().end(), make_pair(x, y)) == shape->getCoordinates().end()) 
            {
                cout << "(" << x << ", " << y << ") ";
                hasPointsInside = true;
            }
        }
    }

    if (!hasPointsInside) 
    {
        cout << "none!";
    }

    cout << "\n";
}

void printShapeInfo(const ShapeTwoD* shape, int counter) 
{
    cout << "Shape [" << counter << "]\n";
    cout << shape->toString() << "\n";
    
    // Initialize bounding box
    int minX = -99;
    int minY = -99;
    int maxX = 99;
    int maxY = 99;

    bool hasPointsInside = false;
    bool hasPointsOnShape = false;

    // check if shape object is circle
    if (const auto *circle = dynamic_cast<const Circle *>(shape))
    {
        int cx, cy, r;
        pair<int, int> center = circle->getCoordinates()[0];
        r = circle->getRadius();
        cx = center.first;
        cy = center.second;
        // Update bounding box based on circle properties
        minX = min(minX, cx - r);
        minY = min(minY, cy - r);
        maxX = max(maxX, cx + r);
        maxY = max(maxY, cy + r);
    }

    // Update bounding box for non circle shapes
    for (const auto &coord : shape->getCoordinates())
    {
        // Update min and max coordinates for the bounding box
        minX = min(minX, coord.first);
        minY = min(minY, coord.second);
        maxX = max(maxX, coord.first);
        maxY = max(maxY, coord.second);
    }

    // Print all coordinates on the shape
    cout << "Points on perimeter:\t";
    printCoordinatesInfo(shape, minX, minY, maxX, maxY, hasPointsInside, hasPointsOnShape);

    cout << "\n\n\n";
}

// Comparison function to sort shapes by special type (ws first), then by area (largest to smallest)
bool compareShapes(const ShapeTwoD* a, const ShapeTwoD* b) 
{
    if (a->getContainsWarpSpace() == b->getContainsWarpSpace()) 
    {
        return a->computeArea() > b->computeArea();
    } 
    else 
    {
        return a->getContainsWarpSpace() > b->getContainsWarpSpace();
    }
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

                cout << "\nRecord successfully stored. Going back to main menu...\n\n";
            }
            break;
            case 2:
            {
                cout << ">>>>>>>>>>>>\t"<< "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
                cout << "Computation complete! ("<< shapes.size() <<"records were updated)\n\n";
            }
            break;
            case 3:
            {
                int counter = 0;
                cout << ">>>>>>>>>>>>\t" << "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
                cout << "Total number of records available: " << shapes.size() << "\n\n";

                for (const ShapeTwoD* shape : shapes) 
                {
                    printShapeInfo(shape, counter);
                    counter++;
                }
            }
            break;
            case 4:
            {
                char option;
                cout << ">>>>>>>>>>>>\t" << "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
                smallmenuprinter();
                while (!(cin >> option) || cin.peek() != '\n' || (option != 'a' && option != 'b' && option != 'c' && option != 'q')) 
                {
                    cout << invalidinp;
                    cin.clear();  // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    smallmenuprinter();
                }

                switch (option)
                {
                    case 'a':
                    {
                        cout << ">>>>>>>>>>>>\t" << "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
                        cout << "Total number of records available: " << shapes.size() << "\n\n";

                        //sort area big to small
                        sort(shapes.begin(), shapes.end(), [&](const ShapeTwoD* a, const ShapeTwoD* b) 
                        {
                            return compareShapesByArea(a, b, false);
                        });

                        int counter = 0;
                        for (const ShapeTwoD* shape : shapes)
                        {
                            printShapeInfo(shape, counter);
                            counter++;
                        }
                    }
                    break;
                    case 'b':
                    {
                        cout << ">>>>>>>>>>>>\t" << "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
                        cout << "Total number of records available: " << shapes.size() << "\n\n";

                        //sort area small to big
                        sort(shapes.begin(), shapes.end(), [&](const ShapeTwoD* a, const ShapeTwoD* b) 
                        {
                            return compareShapesByArea(a, b, true);
                        });

                        int counter = 0;
                        for (const ShapeTwoD* shape : shapes)
                        {
                            printShapeInfo(shape, counter);
                            counter++;
                        }
                    }
                    break;
                    case 'c':
                    {
                        cout << ">>>>>>>>>>>>\t" << "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";

                        // sort shapes by special type (ws first), then by area (largest to smallest)
                        sort(shapes.begin(), shapes.end(), compareShapes);

                        int counter = 0;
                        for (const ShapeTwoD* shape : shapes)
                        {
                            printShapeInfo(shape, counter);
                            counter++;
                        }                       
                    }
                    break;

                    case 'q':
                        // Go back to the main menu
                        break;

                    default:
                        cout << "Invalid option. Please try again.\n";
                        break;
                }
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
