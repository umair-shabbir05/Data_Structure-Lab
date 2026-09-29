#include <iostream>
using namespace std;

int main() {
    // 2 labs, 3 rows per lab, 5 computers per row
    int computers[2][3][5] = {
        {
            {0, 1, 0, 1, 0},
            {1, 0, 0, 1, 0},
            {0, 1, 1, 0, 0}
        },
        {
            {1, 0, 1, 0, 1},
            {0, 0, 1, 1, 0},
            {0, 1, 0, 0, 1}
        }
    };

    int totalAvailable = 0;
    int totalInUse = 0;

    // Display status and count available computers in each lab
    for (int lab = 0; lab < 2; lab++) {
        int labAvailable = 0;

        cout << "\nLab " << lab + 1 << ":" << endl;

        for (int row = 0; row < 3; row++) {
            cout << "  Row " << row + 1 << ": ";

            for (int computer = 0; computer < 5; computer++) {
                cout << computers[lab][row][computer] << " ";

                if (computers[lab][row][computer] == 0) {
                    totalAvailable++;
                    labAvailable++;
                } else {
                    totalInUse++;
                }
            }

            cout << endl;
        }

        cout << "  Available computers in Lab "
             << lab + 1 << ": " << labAvailable << endl;
    }

    // Display total counts
    cout << "\nTotal available computers: "
         << totalAvailable << endl;

    cout << "Total computers currently in use: "
         << totalInUse << endl;

    // Ask the user to select a computer
    int lab, row, computer;

    cout << "\nEnter lab number (1-2): ";
    cin >> lab;

    cout << "Enter row number (1-3): ";
    cin >> row;

    cout << "Enter computer number (1-5): ";
    cin >> computer;

    // Convert user input to array indexes
    lab--;
    row--;
    computer--;

    // Display selected computer's status
    if (computers[lab][row][computer] == 0) {
        cout << "The selected computer is AVAILABLE." << endl;
    } else {
        cout << "The selected computer is IN USE." << endl;
    }

    return 0;
}
