case 3:
{
    cout << ">>>>>>>>>>>>\tOption\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
    cout << "Total number of records available: " << shapes.size() << "\n\n";
    
    for (size_t counter = 0; counter < shapes.size(); ++counter)
    {
        cout << "Shape [" << counter << "]\n";
        cout << shapes[counter]->toString() << "\n";
        
        // Print all coordinates inside the area of the shape
        cout << "Points within shape:\t";
        int minX = 0;
        int minY = 0;
        int maxX = 12;
        int maxY = 8;

        bool hasPointsInside = false; // Flag to check if any points are inside the shape

        for (const auto &coord : shapes[counter]->getCoordinates())
        {
            if (shapes[counter]->isPointInShape(coord.first, coord.second))
            {
                cout << "(" << coord.first << ", " << coord.second << ") ";
                hasPointsInside = true; // Set flag to true if a point is found inside
                // Update min and max coordinates for the bounding box
                minX = min(minX, coord.first);
                minY = min(minY, coord.second);
                maxX = max(maxX, coord.first);
                maxY = max(maxY, coord.second);
            }
        }

        // Check if there are no points inside the shape
        if (!hasPointsInside)
        {
            cout << "none!";
        }

        // Print all coordinates on the shape
        cout << "\nPoints on shape:\t";
        bool hasPointsOnShape = false; // Flag to check if any points are on the shape

        for (int x = minX; x <= maxX; ++x)
        {
            for (int y = minY; y <= maxY; ++y)
            {
                if (shapes[counter]->isPointOnShape(x, y) && find(shapes[counter]->getCoordinates().begin(), shapes[counter]->getCoordinates().end(), make_pair(x, y)) == shapes[counter]->getCoordinates().end())
                {
                    cout << "(" << x << ", " << y << ") ";
                    hasPointsOnShape = true; // Set flag to true if a point is found on the shape
                }
            }
        }

        // Check if there are no points on the shape
        if (!hasPointsOnShape)
        {
            cout << "none!";
        }

        cout << "\n\n\n";
    }
}
break;
