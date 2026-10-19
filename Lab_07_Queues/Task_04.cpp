#include <iostream>
using namespace std;

const int SIZE = 5;

int deque[SIZE];
int front = -1, rear = -1;

// Insert a request at the front
void insertFront(int id)
{
    if ((front == 0 && rear == SIZE - 1) ||
        (front == rear + 1))
    {
        cout << "Deque is full!\n";
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
    {
        front--;
    }

    deque[front] = id;
    cout << "Request " << id << " added at the front.\n";
}

// Insert a request at the rear
void insertRear(int id)
{
    if ((front == 0 && rear == SIZE - 1) ||
        (front == rear + 1))
    {
        cout << "Deque is full!\n";
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = id;
    cout << "Request " << id << " added at the rear.\n";
}

// Remove a request from the front
void deleteFront()
{
    if (front == -1)
    {
        cout << "Deque is empty!\n";
        return;
    }

    cout << "Request " << deque[front] << " removed from the front.\n";

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

// Remove a request from the rear
void deleteRear()
{
    if (front == -1)
    {
        cout << "Deque is empty!\n";
        return;
    }

    cout << "Request " << deque[rear] << " removed from the rear.\n";

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear--;
    }
}

// Display all requests from front to rear
void display()
{
    if (front == -1)
    {
        cout << "Deque is empty!\n";
        return;
    }

    cout << "Requests from front to rear: ";

    int i = front;

    while (true)
    {
        cout << deque[i] << " ";

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main()
{
    int choice, id;

    do
    {
        cout << "\n--- Train Station Passenger Management ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Remove from Front\n";
        cout << "4. Remove from Rear\n";
        cout << "5. Display Requests\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter passenger request ID: ";
                cin >> id;
                insertFront(id);
                break;

            case 2:
                cout << "Enter passenger request ID: ";
                cin >> id;
                insertRear(id);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}