#include <iostream>
using namespace std;

int main() {
    // 3D array: 2 layers, 2 rows, 2 columns
    int arr[2][2][2] = {
        {
            {10, 20},
            {30, 40}
        },
        {
            {50, 60},
            {70, 80}
        }
    };

    // Display the 3D array
    cout << "3D Array:" << endl;

    for (int layer = 0; layer < 2; layer++) {
        cout << "\nLayer " << layer + 1 << ":" << endl;

        for (int row = 0; row < 2; row++) {
            for (int column = 0; column < 2; column++) {
                cout << arr[layer][row][column] << " ";
            }
            cout << endl;
        }
    }

    // Value to search
    int searchValue = 70;
    bool found = false;

    cout << "\nSearching for: " << searchValue << endl;

    // Search the 3D array
    for (int layer = 0; layer < 2; layer++) {
        for (int row = 0; row < 2; row++) {
            for (int column = 0; column < 2; column++) {

                if (arr[layer][row][column] == searchValue) {
                    cout << "\nElement found!" << endl;
                    cout << "Layer: " << layer + 1 << endl;
                    cout << "Row: " << row + 1 << endl;
                    cout << "Column: " << column + 1 << endl;

                    found = true;
                }
            }
        }
    }

    if (!found) {
        cout << "\nElement not found!" << endl;
    }

    return 0;
}
