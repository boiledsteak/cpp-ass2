menuprinter();
        // Check if cin expects an integer
        while (!(cin >> menuchoice)) 
        {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input! Please try again...\n";
            menuprinter();
        }     