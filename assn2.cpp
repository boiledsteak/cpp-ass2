/*============================

Timothy Mah C++ module assignment 2
18 Jan 2024

=============================*/

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <algorithm>

using namespace std;


void menuprinter()
{
    cout << "\n\n\n";
    cout << "Student ID:"  << "\t10258663\n";
    cout << "Student name:"  << "\tTimothy Mah\n";
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
    string gobackmsg = " complete!\n Press ENTER to go back to main menu...";

    while (progflow == 1)
    {
        menuprinter();
        // input validation
        while (!(cin >> menuchoice)) 
        {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input! Please try again...\n";
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

                cout << ">>>>>>>>>>>>\t"<< "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
                cout << "[Input sensor data]\n";
                cout << "Please enter name of the shape:\t";
                getline(cin, shape);
                // validate input
                while (true)
                {
                    if (!shape.empty() && all_of(shape.begin(), shape.end(), ::isalpha))
                    {
                        //some logic with user input shape name
                        cout << "Please enter x-coordinate:\t";
                        // validate if x is integer
                        break;
                    }
                    else
                    {
                        cin.clear();  // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                        cout << "Sorry I do not understand :( Please try again!\n";
                    }
                }
                cout << "\n\n";
                cout << "Please enter special type: ";
                getline(cin, specialtype);
                // validate input
                while (true)
                {
                    if (specialtype == "ws" || specialtype == "ns")
                    {
                        //some logic with user input special type
                        break;
                    }
                    else
                    {
                        cin.clear();  // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                        cout << "Sorry I do not understand :( Please try again!\n";
                    }
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

            }
            break;
            default:
                cout << "\nWe don't have that option :( Please try again...\n\n";
            break;
        }
    }
    return 0;
}