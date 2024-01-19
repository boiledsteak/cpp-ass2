#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    string shape;
    const string invalidinp = "Invalid input. Please enter a valid shape.\n";

    while (true) {
        cout << "Please enter name of the shape:\t";
        getline(cin >> ws, shape); // Ignore whitespace
        // Case insensitive user input
        transform(shape.begin(), shape.end(), shape.begin(), ::tolower);

        if (shape == "square" || shape == "rectangle" || shape == "circle") {
            // TODO: some logic with user input shape name
            cout << "Yep! The shape: " << shape << " is correct!\n";
            break;
        } else {
            cout << invalidinp;
            cin.sync(); // Clear the input buffer
            cin.clear(); // Clear the stream state
        }
    }

    return 0;
}
