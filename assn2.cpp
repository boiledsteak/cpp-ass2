/*============================

Timothy Mah C++ module assignment 2
18 Jan 2024

due 8 Feb 2024

=============================*/

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>

using namespace std;

// my class

// top level parent class

// put in seperate file
// put constructors and functions in ShapeTwoD.cpp
// put private and function prototype in ShapeTwoD.h

// put all this in ShapeTwoD.h
// class ShapeTwoD 
// {
//     private:
//         int id_p; // for testing
        
//         string name;
//         bool containsWarpSpace;
//         vector<map<int, int>> coords;

//     public: // prototypes
//         int getId_p();
//         void setId_p(int id);
// };

// then in ShapeTwoD.cpp, put all the function logic

// this is how to declare child class that inherits from parent class
// put this in square.h
// class square : public ShapeTwoD
// {

// };

// SEE SLIDES S4F


class ShapeTwoD 
{
    protected:
        int id_p; // for testing
        
        string name;
        bool containsWarpSpace;
        vector<map<int, int>> coords;

    public:
        // Getter function for id_p
        int getId_p() 
        {
            return id_p;
        }

        // Setter function for id_p
        void setId_p(int id) 
        {
            id_p = id;
        }
        // Setter function for name
        void setName(string n) 
        {
            name = n;
        }

        // Setter function for containsWarpSpace
        void setContainsWarpSpace(bool space) 
        {
            containsWarpSpace = space;
    }
        // other functions
        /*
        This is a virtual function that returns a string containing all the values of the attributes in the shape, excluding the array of vertex data. (However, sub-classes of ShapeTwoD must output the array of vertex data, inclusive of any other attribute's values it inherited) 
        */        
        string toString()
        {
            return;
        }
        /*
        This is a virtual function. It must be override by the sub-classes and implemented individually. 
        */
        // recommend tobe pure virtual function
        // should have function overriding
        // to calc area of cross -> find the 5 rectangles. big one minus small one
        double computeArea()
        {

            return ;
        }

        /*
        This is a virtual function. It takes in a [ x, y ] location and returns a boolean value indicating whether the location is totally within the shape's area. It must be over-ridden by the sub-classes and implemented individually. 
        */
        // point is inside the shape 
        bool isPointInShape(int x, int y)
        {
            
            return;
        }
        /*
        This is a virtual function. It takes in a [ x, y ] location and returns a boolean value indicating whether the location is found on any lines joining the shapes' vertices! It must be over-ridden by the sub­classes and implemented individually. 
        */
        // point is touching the border / edge of the shape
        bool isPointOnShape(int x, int y)
        {
            
            return;
        }
};

class cross : public ShapeTwoD
{
    private:
        int vert=12;

    public:
        // Public constructor. Shortcut syntax to make code shorter
        cross() : vert(0) {}

        // Getter method
        int getVert() const 
        {
            return vert;
        }
};

class square : public ShapeTwoD
{
    private:
        int vert=4;
    public:
        // Public constructor. Shortcut syntax to make code shorter
        square() : vert(0) {}

        // Getter method
        int getVert() const 
        {
            return vert;
        }
};

class circle : public ShapeTwoD
{
    private:
        int radius;
    
    public:
        // Public constructor. Shortcut syntax to make code shorter
        circle() : radius(0) {}

        // Getter method
        int getRadius() const 
        {
            return radius;
        }

        // Setter method
        void setRadius(int r) 
        {
            radius = r;
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
    string invalidinp = "Sorry I do not understand :( Please try again!\n\n";

    while (progflow == 1)
    {
        menuprinter();
        // input validation
        while (!(cin >> menuchoice)) 
        {
            cin.clear();  // Clear the error flag
            cin.sync(); // Clear the input buffer
            cout << invalidinp;
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
                        //TODO some logic with user input shape name

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
                        cin.sync(); // Clear the input buffer
                        cin.clear();  // Clear the error flag
                    }

                }
                cout << "\n\n";
                // check if shape is circle or not
                if (shape == "circle")
                {
                    //TODO some logic with circle
                    cout << "yep! this is a circle\n";
                    while (true)
                    {
                        cout << "Please enter x coordinate of center: ";
                        cin >> x;
                        // check if x is an integer
                        if (cin.fail())
                        {
                            cout << invalidinp;
                            cin.sync(); // Clear the input buffer
                            cin.clear();  // Clear the error flag
                        }
                        else
                        {
                            //TODO some logic with x coordinate of circle
                            cout << "yep! the x coord of " << x << " is correct!\n";
                            break;
                        }
                    }
                    while (true)
                    {
                        cout << "Please enter y coordinate of center: ";
                        cin >> y;
                        // check if y is an integer
                        if (cin.fail())
                        {
                            cout << invalidinp;
                            cin.sync(); // Clear the input buffer
                            cin.clear();  // Clear the error flag
                        }
                        else
                        {
                            //TODO some logic with y coordinate of circle
                            cout << "yep! the y coord of " << x << " is correct!\n";
                            break;
                        }
                    }
                }
                else
                {
                    //TODO some logic with non cricle shape
                    
                    

                }

                

            }
            break;
            case 2:
            {
                
            }
            break;
            case 3:
            {

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
    return 0;
}