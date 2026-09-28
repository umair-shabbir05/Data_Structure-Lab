#include <iostream>
using namespace std;

// A node represents one patient
class Node {
  public:
    int patientID;
    Node* next;
};

// Add a new patient at the end of the queue
void addPatient(Node*& head, int id) {

    // Create a new node
    Node* newNode = new Node;

    // Store the Patient ID
    newNode->patientID = id;
    newNode->next = NULL;

    // If queue is empty, make this patient the first patient
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Move to the last patient
    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Add new patient at the end
    temp->next = newNode;
}

// Display all patients in the queue
void displayQueue(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << "P" << temp->patientID;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

// Remove the first patient from the queue
void removePatient(Node*& head) {

    // Check if the queue is empty
    if (head == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }

    // Store the first patient's ID
    cout << "Patient P" << head->patientID
         << " is being served." << endl;

    // Move head to the next patient
    Node* temp = head;
    head = head->next;

    // Delete the old first node
    delete temp;
}

int main() {

    // Initially, the queue is empty
    Node* head = NULL;

    // Add patients to the queue
    addPatient(head, 101);
    addPatient(head, 102);
    addPatient(head, 103);
    addPatient(head, 104);

    // Display the original queue
    cout << "Waiting Patients:" << endl;
    displayQueue(head);

    cout << endl;

    // Remove the first patient
    removePatient(head);

    cout << endl;

    // Display the updated queue
    cout << "Updated Queue:" << endl;
    displayQueue(head);

    return 0;
}
