#include <iostream>
#include <string>
using namespace std;

// Node represents one food order
struct Node
{
    string orderID;
    string customerName;
    string foodItem;

    Node* next;   // Pointer to the next order
};

// Function to add a normal order at the end
void addOrderAtEnd(Node*& head)
{
    // Create a new node
    Node* newNode = new Node;

    // Take order information from the user
    cout << "Enter Order ID: ";
    cin >> newNode->orderID;

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, newNode->customerName);

    cout << "Enter Food Item: ";
    getline(cin, newNode->foodItem);

    // New node will be the last node
    newNode->next = NULL;

    // If the list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Start from the first order
        Node* temp = head;

        // Move to the last order
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Add the new order at the end
        temp->next = newNode;
    }

    cout << "Order added successfully.\n";
}

// Function to add an urgent order at the beginning
void addUrgentOrder(Node*& head)
{
    // Create a new node
    Node* newNode = new Node;

    // Take order information
    cout << "Enter Urgent Order ID: ";
    cin >> newNode->orderID;

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, newNode->customerName);

    cout << "Enter Food Item: ";
    getline(cin, newNode->foodItem);

    // New order points to the current first order
    newNode->next = head;

    // New order becomes the first order
    head = newNode;

    cout << "Urgent order added at the beginning.\n";
}

// Function to search for an order using Order ID
void searchOrder(Node* head)
{
    string id;

    cout << "Enter Order ID to search: ";
    cin >> id;

    // Start from the first order
    Node* temp = head;

    // Search until the end of the list
    while (temp != NULL)
    {
        if (temp->orderID == id)
        {
            cout << "\nOrder Found!\n";
            cout << "Order ID: " << temp->orderID << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Food Item: " << temp->foodItem << endl;

            return;
        }

        // Move to the next order
        temp = temp->next;
    }

    // Order was not found
    cout << "Order not found.\n";
}

// Function to remove an order after it has been delivered
void removeOrder(Node*& head)
{
    string id;

    cout << "Enter Order ID that has been delivered: ";
    cin >> id;

    // If the list is empty
    if (head == NULL)
    {
        cout << "Order not found.\n";
        return;
    }

    // If the order to delete is the first order
    if (head->orderID == id)
    {
        Node* temp = head;

        // Move head to the next order
        head = head->next;

        // Delete the old first order
        delete temp;

        cout << "Order delivered and removed successfully.\n";
        return;
    }

    // Start from the first order
    Node* temp = head;

    // Find the order before the order we want to delete
    while (temp->next != NULL)
    {
        if (temp->next->orderID == id)
        {
            // Store the order that will be deleted
            Node* deleteNode = temp->next;

            // Connect previous order to the next order
            temp->next = deleteNode->next;

            // Delete the delivered order
            delete deleteNode;

            cout << "Order delivered and removed successfully.\n";
            return;
        }

        // Move to the next order
        temp = temp->next;
    }

    // Order ID was not found
    cout << "Order not found.\n";
}

// Function to display all pending orders
void displayOrders(Node* head)
{
    // Check if there are no pending orders
    if (head == NULL)
    {
        cout << "No pending orders.\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== Pending Orders =====\n";

    // Display every order
    while (temp != NULL)
    {
        cout << "Order ID: " << temp->orderID << endl;
        cout << "Customer Name: " << temp->customerName << endl;
        cout << "Food Item: " << temp->foodItem << endl;
        cout << "--------------------------\n";

        // Move to the next order
        temp = temp->next;
    }
}

// Main function
int main()
{
    // Initially, there are no pending orders
    Node* head = NULL;

    int choice;

    do
    {
        cout << "\n===== Online Food Delivery System =====\n";
        cout << "1. Add New Order at End\n";
        cout << "2. Display Pending Orders\n";
        cout << "3. Search Order\n";
        cout << "4. Remove Delivered Order\n";
        cout << "5. Add Urgent Order at Beginning\n";
        cout << "6. Display Updated Pending Orders\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addOrderAtEnd(head);
                break;

            case 2:
                displayOrders(head);
                break;

            case 3:
                searchOrder(head);
                break;

            case 4:
                removeOrder(head);
                break;

            case 5:
                addUrgentOrder(head);
                break;

            case 6:
                displayOrders(head);
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