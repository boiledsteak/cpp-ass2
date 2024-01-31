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

#include "shapetwod.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "cross.h"
#include "functions.h"

using namespace std;

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
