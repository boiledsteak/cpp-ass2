case 1:
{
    string shape;
    string specialtype;
    int x;
    int y;

    cout << ">>>>>>>>>>>>\t" << "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
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
            cin.clear(); // Clear the error flag
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
            cout << "yep! the special type: " << specialtype << " is correct!\n";
            break;
        }
        else
        {
            cout << invalidinp;
            cin.sync(); // Clear the input buffer
            cin.clear(); // Clear the error flag
        }
    }
    cout << "\n\n";

    // Check if shape is circle or not
    if (shape == "circle")
    {
        // TODO: logic for circle
        cout << "yep! this is a circle\n";
    }
    else if (shape == "square" || shape == "rectangle")
    {
        // Create Square object and set its properties
        Square square;
        square.setName(shape);
        square.setContainsWarpSpace(specialtype == "ws");

        // Get coordinates for the square
        for (int i = 0; i < Square::numCoordinates; ++i)
        {
            cout << "Please enter x coordinate for point " << i + 1 << ": ";
            cin >> x;

            // Validate x coordinate
            while (cin.fail())
            {
                cout << invalidinp;
                cin.clear();  // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Please enter x coordinate for point " << i + 1 << ": ";
                cin >> x;
            }

            cout << "Please enter y coordinate for point " << i + 1 << ": ";
            cin >> y;

            // Validate y coordinate
            while (cin.fail())
            {
                cout << invalidinp;
                cin.clear();  // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Please enter y coordinate for point " << i + 1 << ": ";
                cin >> y;
            }

            // Set coordinates for the square
            square.setCoordinates({{x, y}}, Square::numCoordinates);
        }

        // Print information about the square
        cout << square.toString() << endl;
    }
    else
    {
        // TODO: logic for other shapes
    }
}
break;
