#include <iostream>
using namespace std;

const int SIZE = 5;

int queue[SIZE];
int front = -1, rear = -1;

// Insert a packet into the circular queue
void enqueue(int packet)
{
    // Check if the queue is full
    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue is full! Cannot add packet.\n";
        return;
    }

    // Insert the first packet
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        // Move rear circularly
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = packet;

    cout << "Packet " << packet << " added successfully.\n";
}

// Transmit the oldest packet
void dequeue()
{
    // Check if the queue is empty
    if (front == -1)
    {
        cout << "Queue is empty! No packets to transmit.\n";
        return;
    }

    cout << "Packet " << queue[front] << " transmitted.\n";

    // If only one packet exists, reset the queue
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        // Move front circularly
        front = (front + 1) % SIZE;
    }
}

// Display all packets waiting for transmission
void display()
{
    if (front == -1)
    {
        cout << "No packets waiting for transmission.\n";
        return;
    }

    cout << "Packets waiting: ";

    int i = front;

    while (true)
    {
        cout << queue[i] << " ";

        if (i == rear)
        {
            break;
        }

        // Move to the next position circularly
        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main()
{
    int choice, packet;

    do
    {
        cout << "\n--- Network Packet Management ---\n";
        cout << "1. Insert Packet\n";
        cout << "2. Transmit Packet\n";
        cout << "3. Display Waiting Packets\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter packet ID: ";
                cin >> packet;
                enqueue(packet);
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