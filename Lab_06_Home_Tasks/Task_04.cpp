
#include <iostream>
using namespace std;

// Name: Umair Shabbir
// Reg. ID: 2502027
// Task No: 04
// Problem: Two Stacks in One Array - Library Management

const int SIZE = 10;

// Class for implementing two stacks in one array
class TwoStacks
{
private:
    int arr[SIZE];
    int top1;
    int top2;

public:
    // Constructor
    TwoStacks()
    {
        top1 = -1;
        top2 = SIZE;
    }

    // PUSH operation for Stack 1
    void push1(int book)
    {
        if (top1 + 1 == top2)
        {
            cout << "No space available for Stack 1!" << endl;
            return;
        }

        top1++;
        arr[top1] = book;
    }

    // PUSH operation for Stack 2
    void push2(int book)
    {
        if (top1 + 1 == top2)
        {
            cout << "No space available for Stack 2!" << endl;
            return;
        }

        top2--;
        arr[top2] = book;
    }

    // POP operation for Stack 1
    int pop1()
    {
        if (top1 == -1)
        {
            cout << "Available Books Stack is Empty!" << endl;
            return -1;
        }

        int book = arr[top1];
        top1--;

        return book;
    }

    // POP operation for Stack 2
    int pop2()
    {
        if (top2 == SIZE)
        {
            cout << "Returned Books Stack is Empty!" << endl;
            return -1;
        }

        int book = arr[top2];
        top2++;

        return book;
    }

    // TOP operation for Stack 1
    int topStack1()
    {
        if (top1 == -1)
        {
            return -1;
        }

        return arr[top1];
    }

    // TOP operation for Stack 2
    int topStack2()
    {
        if (top2 == SIZE)
        {
            return -1;
        }

        return arr[top2];
    }

    // Display Stack 1
    void display1()
    {
        cout << "Available Books: ";

        if (top1 == -1)
        {
            cout << "Empty";
        }

        for (int i = 0; i <= top1; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Display Stack 2
    void display2()
    {
        cout << "Returned Books: ";

        if (top2 == SIZE)
        {
            cout << "Empty";
        }

        for (int i = SIZE - 1; i >= top2; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    TwoStacks library;

    // PUSH books into Available Books Stack
    library.push1(101);
    library.push1(102);
    library.push1(103);

    // PUSH books into Returned Books Stack
    library.push2(201);
    library.push2(202);
    library.push2(203);

    // Display both stacks
    cout << "Library Management System" << endl;
    cout << "-------------------------" << endl;

    library.display1();
    library.display2();

    // Display TOP elements
    cout << "\nTop of Available Books: "
         << library.topStack1() << endl;

    cout << "Top of Returned Books: "
         << library.topStack2() << endl;

    // Perform POP operations
    cout << "\nRemoving Top Books:" << endl;

    cout << "Popped from Available Books: "
         << library.pop1() << endl;

    cout << "Popped from Returned Books: "
         << library.pop2() << endl;

    // Display stacks after POP
    cout << "\nAfter POP Operations:" << endl;

    library.display1();
    library.display2();

    return 0;
}
