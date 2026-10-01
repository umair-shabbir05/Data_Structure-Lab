#include <iostream>
#include <string>
using namespace std;

// Node represents one student
struct Node
{
    int rollNumber;
    string studentName;
    string attendanceStatus;

    Node* next;   // Pointer to the next student
};

// Function to add a student to the attendance list
void addStudent(Node*& head)
{
    // Create a new node
    Node* newNode = new Node;

    // Take student information from the user
    cout << "Enter Roll Number: ";
    cin >> newNode->rollNumber;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, newNode->studentName);

    cout << "Enter Attendance Status (Present/Absent): ";
    cin >> newNode->attendanceStatus;

    // New node will be the last node
    newNode->next = NULL;

    // If the list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Start from the first student
        Node* temp = head;

        // Move to the last student
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Add the new student at the end
        temp->next = newNode;
    }

    cout << "Student added successfully.\n";
}

// Function to search for a student using Roll Number
void searchStudent(Node* head)
{
    int roll;

    cout << "Enter Roll Number to search: ";
    cin >> roll;

    Node* temp = head;

    // Search through the linked list
    while (temp != NULL)
    {
        if (temp->rollNumber == roll)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << temp->rollNumber << endl;
            cout << "Student Name: " << temp->studentName << endl;
            cout << "Attendance: " << temp->attendanceStatus << endl;

            return;
        }

        // Move to the next student
        temp = temp->next;
    }

    // If student was not found
    cout << "Student not found.\n";
}

// Function to delete a student using Roll Number
void deleteStudent(Node*& head)
{
    int roll;

    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    // Check if the list is empty
    if (head == NULL)
    {
        cout << "Student not found.\n";
        return;
    }

    // If the student to delete is the first student
    if (head->rollNumber == roll)
    {
        Node* temp = head;

        // Move head to the second student
        head = head->next;

        // Delete the first student
        delete temp;

        cout << "Student deleted successfully.\n";
        return;
    }

    // Start from the first student
    Node* temp = head;

    // Find the student before the student we want to delete
    while (temp->next != NULL)
    {
        if (temp->next->rollNumber == roll)
        {
            // Store the student that will be deleted
            Node* deleteNode = temp->next;

            // Connect previous student to the next student
            temp->next = deleteNode->next;

            // Delete the student
            delete deleteNode;

            cout << "Student deleted successfully.\n";
            return;
        }

        // Move to the next student
        temp = temp->next;
    }

    // If roll number was not found
    cout << "Student not found.\n";
}

// Function to display all students
void displayStudents(Node* head)
{
    // Check if the list is empty
    if (head == NULL)
    {
        cout << "No students in the attendance list.\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== Attendance List =====\n";

    // Display every student
    while (temp != NULL)
    {
        cout << "Roll Number: " << temp->rollNumber << endl;
        cout << "Student Name: " << temp->studentName << endl;
        cout << "Attendance: " << temp->attendanceStatus << endl;
        cout << "---------------------------\n";

        // Move to the next student
        temp = temp->next;
    }
}

// Function to count students who are present
void countPresentStudents(Node* head)
{
    int count = 0;

    Node* temp = head;

    // Check every student
    while (temp != NULL)
    {
        // If attendance status is Present
        if (temp->attendanceStatus == "Present" ||
            temp->attendanceStatus == "present")
        {
            count++;
        }

        // Move to the next student
        temp = temp->next;
    }

    cout << "Total Students Present: " << count << endl;
}

// Main function
int main()
{
    // Initially, the linked list is empty
    Node* head = NULL;

    int choice;

    do
    {
        cout << "\n===== University Student Attendance List =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Count Total Students Present\n";
        cout << "6. Display Final Attendance List\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent(head);
                break;

            case 2:
                searchStudent(head);
                break;

            case 3:
                deleteStudent(head);
                break;

            case 4:
                displayStudents(head);
                break;

            case 5:
                countPresentStudents(head);
                break;

            case 6:
                displayStudents(head);
                break;

            case 7:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}