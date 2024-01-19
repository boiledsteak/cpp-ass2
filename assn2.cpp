/*============================

Timothy Mah C++ module assignment 2
18 Jan 2024

=============================*/

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <algorithm>
#include <cctype>

using namespace std;


void menuprinter()
{
    cout << "\n\n\n";
    cout << "Student ID:" << "\t10258663\n";
    cout << "Student name:" << "\tTimothy Mah\n";
    cout << "------------------------------------------------------\n";
    cout << "Welcome to Assignment 2 program!\n\n";
    cout << "1)" << "\tInput sensor data\n";
    cout << "2)" << "\tCompute area (for all records)\n";
    cout << "3)" << "\tPrint shapes report\n";
    cout << "4)" << "\tSort shape data\n";
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
                    if (shape == "square" || shape == "rectangle" || shape == "circle")
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