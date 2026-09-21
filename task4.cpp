#include <iostream>
using namespace std;

int main() {
    // 3 floors, 3 wards per floor, 4 beds per ward
    int beds[3][3][4] = {
        {
            {0, 1, 0, 1},
            {1, 0, 0, 1},
            {0, 0, 1, 0}
        },
        {
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1}
        },
        {
            {1, 0, 1, 0},
            {1, 1, 0, 0},
            {0, 1, 0, 1}
        }
    };

    int totalOccupied = 0;
    int totalAvailable = 0;

    // Display bed status and count occupied beds on each floor
    for (int floor = 0; floor < 3; floor++) {
        int floorOccupied = 0;

        cout << "\nFloor " << floor + 1 << ":" << endl;

        for (int ward = 0; ward < 3; ward++) {
            cout << "  Ward " << ward + 1 << ": ";

            for (int bed = 0; bed < 4; bed++) {
                cout << beds[floor][ward][bed] << " ";

                if (beds[floor][ward][bed] == 1) {
                    totalOccupied++;
                    floorOccupied++;
                } else {
                    totalAvailable++;
                }
            }

            cout << endl;
        }

        cout << "  Occupied beds on Floor " << floor + 1
             << ": " << floorOccupied << endl;
    }

    // Display total occupied and available beds
    cout << "\nTotal occupied beds: " << totalOccupied << endl;
    cout << "Total available beds: " << totalAvailable << endl;

    // Ask the user to select a bed
    int floor, ward, bed;

    cout << "\nEnter floor number (1-3): ";
    cin >> floor;

    cout << "Enter ward number (1-3): ";
    cin >> ward;

    cout << "Enter bed number (1-4): ";
    cin >> bed;

    // Convert user input to array indexes
    floor--;
    ward--;
    bed--;

    // Display selected bed status
    if (beds[floor][ward][bed] == 0) {
        cout << "The selected bed is AVAILABLE." << endl;
    } else {
        cout << "The selected bed is OCCUPIED." << endl;
    }

    return 0;
}
