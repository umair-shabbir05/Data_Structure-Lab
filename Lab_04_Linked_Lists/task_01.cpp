#include <iostream>
using namespace std;

// A node represents one student
struct Node {
    int rollNumber;
    Node* next;
};

// Add a new student at the end of the list
void addStudent(Node*& head, int rollNumber) {

    // Create a new node
    Node* newNode = new Node;

    // Store the roll number
    newNode->rollNumber = rollNumber;
    newNode->next = NULL;

    // If the list is empty, make this node the first node
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Move to the last node
    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Add the new node at the end
    temp->next = newNode;
}

// Display all registered students
void displayStudents(Node* head) {

    cout << "Registered Students: ";

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->rollNumber;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

// Search for a student using Roll Number
void searchStudent(Node* head, int rollNumber) {

    Node* temp = head;

    // Check each node
    while (temp != NULL) {

        if (temp->rollNumber == rollNumber) {
            cout << "Student Found" << endl;
            return;
        }

        temp = temp->next;
    }

    // If roll number was not found
    cout << "Student Not Found" << endl;
}

int main() {

    // Initially, the list is empty
    Node* head = NULL;

    // Add students
    addStudent(head, 101);
    addStudent(head, 105);
    addStudent(head, 108);
    addStudent(head, 112);

    // Display all students
    displayStudents(head);

    // Ask the user for a Roll Number to search
    int rollNumber;

    cout << "Enter Roll Number to Search: ";
    cin >> rollNumber;

    // Search for the student
    searchStudent(head, rollNumber);

    return 0;
}
#include <iostream>
using namespace std;

// A node represents one student
struct Node {
    int rollNumber;
    Node* next;
};

// Add a new student at the end of the list
void addStudent(Node*& head, int rollNumber) {

    // Create a new node
    Node* newNode = new Node;

    // Store the roll number
    newNode->rollNumber = rollNumber;
    newNode->next = NULL;

    // If the list is empty, make this node the first node
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Move to the last node
    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Add the new node at the end
    temp->next = newNode;
}

// Display all registered students
void displayStudents(Node* head) {

    cout << "Registered Students: ";

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->rollNumber;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

// Search for a student using Roll Number
void searchStudent(Node* head, int rollNumber) {

    Node* temp = head;

    // Check each node
    while (temp != NULL) {

        if (temp->rollNumber == rollNumber) {
            cout << "Student Found" << endl;
            return;
        }

        temp = temp->next;
    }

    // If roll number was not found
    cout << "Student Not Found" << endl;
}

int main() {

    // Initially, the list is empty
    Node* head = NULL;

    // Add students
    addStudent(head, 101);
    addStudent(head, 105);
    addStudent(head, 108);
    addStudent(head, 112);

    // Display all students
    displayStudents(head);

    // Ask the user for a Roll Number to search
    int rollNumber;

    cout << "Enter Roll Number to Search: ";
    cin >> rollNumber;

    // Search for the student
    searchStudent(head, rollNumber);

    return 0;
}
#include <iostream>
using namespace std;

// A node represents one student
struct Node {
    int rollNumber;
    Node* next;
};

// Add a new student at the end of the list
void addStudent(Node*& head, int rollNumber) {

    // Create a new node
    Node* newNode = new Node;

    // Store the roll number
    newNode->rollNumber = rollNumber;
    newNode->next = NULL;

    // If the list is empty, make this node the first node
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Move to the last node
    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Add the new node at the end
    temp->next = newNode;
}

// Display all registered students
void displayStudents(Node* head) {

    cout << "Registered Students: ";

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->rollNumber;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

// Search for a student using Roll Number
void searchStudent(Node* head, int rollNumber) {

    Node* temp = head;

    // Check each node
    while (temp != NULL) {

        if (temp->rollNumber == rollNumber) {
            cout << "Student Found" << endl;
            return;
        }

        temp = temp->next;
    }

    // If roll number was not found
    cout << "Student Not Found" << endl;
}

int main() {

    // Initially, the list is empty
    Node* head = NULL;

    // Add students
    addStudent(head, 101);
    addStudent(head, 105);
    addStudent(head, 108);
    addStudent(head, 112);

    // Display all students
    displayStudents(head);

    // Ask the user for a Roll Number to search
    int rollNumber;

    cout << "Enter Roll Number to Search: ";
    cin >> rollNumber;

    // Search for the student
    searchStudent(head, rollNumber);

    return 0;
}
