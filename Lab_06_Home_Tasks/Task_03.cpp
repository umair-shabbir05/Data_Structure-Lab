
#include <iostream>
using namespace std;

// Name: Umair Shabbir
// Reg. ID: 2502027
// Task No: 03
// Problem: Next Greater Element using Linked List Stack

// Node structure
struct Node
{
    int data;
    Node* next;
};

// Stack class using Singly Linked List
class Stack
{
private:
    Node* top;

public:
    // Constructor
    Stack()
    {
        top = NULL;
    }

    // PUSH operation
    void push(int value)
    {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = top;

        top = newNode;
    }

    // POP operation
    int pop()
    {
        if (top == NULL)
        {
            return -1;
        }

        Node* temp = top;
        int value = temp->data;

        top = top->next;

        delete temp;

        return value;
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // Destructor
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

// Function to find Next Greater Element
void findNextGreater(int arr[], int n)
{
    int result[5];

    Stack s;

    // Traverse array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // Remove smaller or equal temperatures
        while (!s.isEmpty() && s.pop() <= arr[i])
        {
            // Keep removing until a greater value is found
        }

        // Find next greater element
        if (s.isEmpty())
        {
            result[i] = -1;
        }
        else
        {
            result[i] = s.pop();
        }

        // Push current temperature
        s.push(arr[i]);
    }

    // Display results
    cout << "\nTemperature\tNext Greater Temperature" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t\t" << result[i] << endl;
    }
}

int main()
{
    int temperatures[] = {30, 35, 28, 40, 32};

    int n = 5;

    cout << "Daily Temperature Readings: ";

    for (int i = 0; i < n; i++)
    {
        cout << temperatures[i] << " ";
    }

    findNextGreater(temperatures, n);

    return 0;
}
