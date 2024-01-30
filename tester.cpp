#include <iostream>
#include <limits> // For numeric_limits

using namespace std;

int main() 
{
    int menuchoice;
    int menuchoice2;
    int menuchoice3;

    cout << "Choose an integer:\n";
    
    while (true) 
    {
        cin >> menuchoice;

        // Check if the input is a valid integer
        if (cin.fail() || cin.peek() != '\n') 
        {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input! Please enter an integer. Try again...\n";
            cout << "Choose an integer:\n";
        } 
        else 
        {
            break;  // Exit the loop if the input is a valid integer
        }
    } 

    cout << "Choose an integer2:\n";
    
    while (true) 
    {
        cin >> menuchoice2;

        // Check if the input is a valid integer
        if (cin.fail() || cin.peek() != '\n') 
        {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input! Please enter an integer. Try again...\n";
            cout << "Choose an integer2:\n";
        } 
        else 
        {
            break;  // Exit the loop if the input is a valid integer
        }
    } 

    cout << "Choose an integer3:\n";
    
    while (true) 
    {
        cin >> menuchoice3;

        // Check if the input is a valid integer
        if (cin.fail() || cin.peek() != '\n') 
        {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input! Please enter an integer. Try again...\n";
            cout << "Choose an integer3:\n";
        } 
        
        else 
        {
            break;  // Exit the loop if the input is a valid integer
        }
    } 

    cout << "You chose: " << endl << menuchoice << endl << menuchoice2 << endl << menuchoice3 << endl;
    return 0;
}
