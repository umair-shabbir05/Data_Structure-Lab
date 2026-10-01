#include <iostream>
#include <string>
using namespace std;

// Node represents one course
struct Node
{
    string courseCode;
    string courseName;
    int creditHours;

    Node* next;   // Pointer to the next course
};


// Function to add a course at the beginning
void addAtBeginning(Node*& head)
{
    // Create a new node
    Node* newNode = new Node;

    // Take course information from the user
    cout << "Enter Course Code: ";
    cin >> newNode->courseCode;

    cout << "Enter Course Name: ";
    cin.ignore();
    getline(cin, newNode->courseName);

    cout << "Enter Credit Hours: ";
    cin >> newNode->creditHours;

    // New course points to the current first course
    newNode->next = head;

    // New course becomes the first course
    head = newNode;

    cout << "Course added at the beginning successfully.\n";
}


// Function to add a course at the end
void addAtEnd(Node*& head)
{
    // Create a new node
    Node* newNode = new Node;

    // Take course information from the user
    cout << "Enter Course Code: ";
    cin >> newNode->courseCode;

    cout << "Enter Course Name: ";
    cin.ignore();
    getline(cin, newNode->courseName);

    cout << "Enter Credit Hours: ";
    cin >> newNode->creditHours;

    // New node will be the last node
    newNode->next = NULL;

    // If the list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Start from the first course
        Node* temp = head;

        // Move to the last course
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Add the new course at the end
        temp->next = newNode;
    }

    cout << "Course added at the end successfully.\n";
}


// Function to search for a course using Course Code
void searchCourse(Node* head)
{
    string code;

    cout << "Enter Course Code to search: ";
    cin >> code;

    Node* temp = head;

    // Search through the linked list
    while (temp != NULL)
    {
        if (temp->courseCode == code)
        {
            cout << "\nCourse Found!\n";
            cout << "Course Code: " << temp->courseCode << endl;
            cout << "Course Name: " << temp->courseName << endl;
            cout << "Credit Hours: " << temp->creditHours << endl;

            return;
        }

        // Move to the next course
        temp = temp->next;
    }

    // Course was not found
    cout << "Course not found.\n";
}


// Function to delete a course using Course Code
void deleteCourse(Node*& head)
{
    string code;

    cout << "Enter Course Code to delete: ";
    cin >> code;

    // Check if the list is empty
    if (head == NULL)
    {
        cout << "Course not found.\n";
        return;
    }

    // If the course to delete is the first course
    if (head->courseCode == code)
    {
        Node* temp = head;

        // Move head to the next course
        head = head->next;

        // Delete the old first course
        delete temp;

        cout << "Course deleted successfully.\n";
        return;
    }

    // Start from the first course
    Node* temp = head;

    // Find the course before the course we want to delete
    while (temp->next != NULL)
    {
        if (temp->next->courseCode == code)
        {
            // Store the course that will be deleted
            Node* deleteNode = temp->next;

            // Connect previous course to the next course
            temp->next = deleteNode->next;

            // Delete the course
            delete deleteNode;

            cout << "Course deleted successfully.\n";
            return;
        }

        // Move to the next course
        temp = temp->next;
    }

    // Course Code was not found
    cout << "Course not found.\n";
}


// Function to display all courses
void displayCourses(Node* head)
{
    // Check if the list is empty
    if (head == NULL)
    {
        cout << "No courses in the list.\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== Course List =====\n";

    // Display every course
    while (temp != NULL)
    {
        cout << "Course Code: " << temp->courseCode << endl;
        cout << "Course Name: " << temp->courseName << endl;
        cout << "Credit Hours: " << temp->creditHours << endl;
        cout << "-----------------------\n";

        // Move to the next course
        temp = temp->next;
    }
}


// Function to count the total number of courses
void countCourses(Node* head)
{
    int count = 0;

    Node* temp = head;

    // Visit every node
    while (temp != NULL)
    {
        count++;

        // Move to the next course
        temp = temp->next;
    }

    cout << "Total Courses: " << count << endl;
}


// Function to concatenate the second list
// at the end of the first list
void concatenateLists(Node*& firstList, Node* secondList)
{
    // If the first list is empty,
    // make the second list the first list
    if (firstList == NULL)
    {
        firstList = secondList;
        return;
    }

    // Start from the first course
    Node* temp = firstList;

    // Move to the last course of first list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Connect the last course of first list
    // to the first course of second list
    temp->next = secondList;
}


// Main function
int main()
{
    // First course list
    Node* courseList1 = NULL;

    // Second course list
    Node* courseList2 = NULL;

    int choice;

    do
    {
        cout << "\n===== University Course Management =====\n";
        cout << "1. Add Course at Beginning\n";
        cout << "2. Add Course at End\n";
        cout << "3. Search Course\n";
        cout << "4. Delete Course\n";
        cout << "5. Display All Courses\n";
        cout << "6. Count Total Courses\n";
        cout << "7. Concatenate Another Course List\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addAtBeginning(courseList1);
                break;

            case 2:
                addAtEnd(courseList1);
                break;

            case 3:
                searchCourse(courseList1);
                break;

            case 4:
                deleteCourse(courseList1);
                break;

            case 5:
                displayCourses(courseList1);
                break;

            case 6:
                countCourses(courseList1);
                break;

            case 7:
            {
                cout << "\n===== Enter Courses for Second List =====\n";

                int numberOfCourses;

                cout << "How many courses do you want to add to the second list? ";
                cin >> numberOfCourses;

                // Add courses to the second list
                for (int i = 0; i < numberOfCourses; i++)
                {
                    cout << "\nCourse " << i + 1 << ":\n";
                    addAtEnd(courseList2);
                }

                // Join second list with first list
                concatenateLists(courseList1, courseList2);

                // Display the combined list
                cout << "\n===== Combined Course List =====\n";
                displayCourses(courseList1);

                // Avoid using courseList2 separately after joining
                courseList2 = NULL;

                break;
            }

            case 8:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}