#include <iostream>
#include <string>
using namespace std;

// Node represents one patient
struct Node
{
    int patientID;
    string patientName;
    int patientAge;

    Node* next;   // Pointer to the next patient
};

// Function to add a normal patient at the end
void addPatientAtEnd(Node*& head)
{
    Node* newNode = new Node;

    // Take patient information from the user
    cout << "Enter Patient ID: ";
    cin >> newNode->patientID;

    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, newNode->patientName);

    cout << "Enter Patient Age: ";
    cin >> newNode->patientAge;

    // New node will be the last node
    newNode->next = NULL;

    // If the list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Start from the first patient
        Node* temp = head;

        // Move until the last patient
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Attach the new patient at the end
        temp->next = newNode;
    }

    cout << "Patient added successfully.\n";
}

// Function to add an emergency patient at the beginning
void addEmergencyPatient(Node*& head)
{
    Node* newNode = new Node;

    // Take patient information
    cout << "Enter Emergency Patient ID: ";
    cin >> newNode->patientID;

    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, newNode->patientName);

    cout << "Enter Patient Age: ";
    cin >> newNode->patientAge;

    // New patient points to the current first patient
    newNode->next = head;

    // New patient becomes the first patient
    head = newNode;

    cout << "Emergency patient added at the beginning.\n";
}

// Function to search for a patient using Patient ID
void searchPatient(Node* head)
{
    int id;

    cout << "Enter Patient ID to search: ";
    cin >> id;

    Node* temp = head;

    // Search until the end of the list
    while (temp != NULL)
    {
        if (temp->patientID == id)
        {
            cout << "\nPatient Found!\n";
            cout << "Patient ID: " << temp->patientID << endl;
            cout << "Patient Name: " << temp->patientName << endl;
            cout << "Patient Age: " << temp->patientAge << endl;

            return;
        }

        temp = temp->next;
    }

    // If the loop finishes, patient was not found
    cout << "Patient not found.\n";
}

// Function to remove a patient using Patient ID
void removePatient(Node*& head)
{
    int id;

    cout << "Enter Patient ID to remove: ";
    cin >> id;

    // If the list is empty
    if (head == NULL)
    {
        cout << "Patient not found.\n";
        return;
    }

    // If the patient to delete is the first patient
    if (head->patientID == id)
    {
        Node* temp = head;

        head = head->next;

        delete temp;

        cout << "Patient removed successfully.\n";
        return;
    }

    // Start searching from the first patient
    Node* temp = head;

    // Find the patient before the patient we want to delete
    while (temp->next != NULL)
    {
        if (temp->next->patientID == id)
        {
            Node* deleteNode = temp->next;

            // Connect previous patient to the next patient
            temp->next = deleteNode->next;

            // Delete the patient
            delete deleteNode;

            cout << "Patient removed successfully.\n";
            return;
        }

        temp = temp->next;
    }

    // Patient ID was not found
    cout << "Patient not found.\n";
}

// Function to display all waiting patients
void displayPatients(Node* head)
{
    // Check if there are no patients
    if (head == NULL)
    {
        cout << "No patients are waiting.\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== Waiting Patients =====\n";

    // Display every patient
    while (temp != NULL)
    {
        cout << "Patient ID: " << temp->patientID << endl;
        cout << "Patient Name: " << temp->patientName << endl;
        cout << "Patient Age: " << temp->patientAge << endl;
        cout << "---------------------------\n";

        temp = temp->next;
    }
}

// Main function
int main()
{
    // Initially, the linked list is empty
    Node* head = NULL;

    int choice;

    do
    {
        cout << "\n===== Hospital Emergency Patient Management =====\n";
        cout << "1. Add New Patient at End\n";
        cout << "2. Add Emergency Patient at Beginning\n";
        cout << "3. Search Patient\n";
        cout << "4. Remove Patient After Treatment\n";
        cout << "5. Display All Waiting Patients\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addPatientAtEnd(head);
                break;

            case 2:
                addEmergencyPatient(head);
                break;

            case 3:
                searchPatient(head);
                break;

            case 4:
                removePatient(head);
                break;

            case 5:
                displayPatients(head);
                break;

            case 6:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}