#include <iostream>
using namespace std;

const int SIZE = 5;

int queue[SIZE];
int front = -1, rear = -1;

// Insert a customer token into the queue
void enqueue(int token)
{
    // Check for overflow
    if (rear == SIZE - 1)
    {
        cout << "Queue Overflow! No space available.\n";
        return;
    }

    // Insert the first customer
    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = token;

    cout << "Customer " << token << " added to the queue.\n";
}

// Serve the next customer
void dequeue()
{
    // Check for underflow
    if (front == -1)
    {
        cout << "Queue Underflow! No customers waiting.\n";
        return;
    }

    cout << "Customer " << queue[front] << " has been served.\n";

    // If the last customer is served, reset the queue
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

// Display all waiting customers
void display()
{
    if (front == -1)
    {
        cout << "No customers waiting.\n";
        return;
    }

    cout << "Waiting customers: ";

    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }

    cout << endl;
}

// Display the number of waiting customers
void countCustomers()
{
    if (front == -1)
    {
        cout << "Number of waiting customers: 0\n";
    }
    else
    {
        cout << "Number of waiting customers: "
             << rear - front + 1 << endl;
    }
}

int main()
{
    int choice, token;

    do
    {
        cout << "\n--- Bank Customer Service System ---\n";
        cout << "1. Add Customer (Enqueue)\n";
        cout << "2. Serve Customer (Dequeue)\n";
        cout << "3. Display Waiting Customers\n";
        cout << "4. Count Waiting Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter customer token number: ";
                cin >> token;
                enqueue(token);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                countCustomers();
                break;

            case 5:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}