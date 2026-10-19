#include <iostream>
using namespace std;

const int SIZE = 5;

struct Patient
{
    int id;
    int priority;
};

Patient queue[SIZE];
int count = 0;

// Insert a patient according to priority
void enqueue(int id, int priority)
{
    if (count == SIZE)
    {
        cout << "Queue is full! Cannot add more patients.\n";
        return;
    }

    Patient newPatient;
    newPatient.id = id;
    newPatient.priority = priority;

    int i = count - 1;

    // Arrange patients so the highest priority comes first
    // Smaller priority number means greater urgency
    while (i >= 0 && queue[i].priority > priority)
    {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1] = newPatient;
    count++;

    cout << "Patient P" << id << " added successfully.\n";
}

// Treat the patient with the highest priority
void dequeue()
{
    if (count == 0)
    {
        cout << "Queue is empty! No patients waiting.\n";
        return;
    }

    cout << "Treating Patient P" << queue[0].id
         << " with priority " << queue[0].priority << ".\n";

    // Shift remaining patients forward
    for (int i = 0; i < count - 1; i++)
    {
        queue[i] = queue[i + 1];
    }

    count--;
}

// Display all waiting patients
void display()
{
    if (count == 0)
    {
        cout << "No patients waiting.\n";
        return;
    }

    cout << "\nWaiting Patients:\n";

    for (int i = 0; i < count; i++)
    {
        cout << "Patient ID: P" << queue[i].id
             << " | Priority: " << queue[i].priority << endl;
    }
}

int main()
{
    int choice, id, priority;

    do
    {
        cout << "\n--- Hospital Emergency Department ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Highest Priority Patient\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter patient ID (e.g., 102): ";
                cin >> id;

                cout << "Enter priority (1 = highest): ";
                cin >> priority;

                enqueue(id, priority);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}