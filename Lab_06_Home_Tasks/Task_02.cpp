
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Name: Umair Shabbir
// Reg. ID: 2502027
// Task No: 02
// Problem: Postfix Expression Evaluation using Array Stack

const int SIZE = 100;

// Stack class using array
class Stack
{
private:
    int arr[SIZE];
    int top;

public:
    // Constructor
    Stack()
    {
        top = -1;
    }

    // PUSH operation
    void push(int value)
    {
        if (top == SIZE - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    // POP operation
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
            return 0;
        }

        int value = arr[top];
        top--;
        return value;
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return top == -1;
    }
};

// Function to evaluate postfix expression
int evaluatePostfix(string expression)
{
    Stack s;
    stringstream ss(expression);
    string token;

    while (ss >> token)
    {
        // Check if token is an operator
        if (token == "+" || token == "-" ||
            token == "*" || token == "/")
        {
            // POP two operands
            int b = s.pop();
            int a = s.pop();

            // Perform operation
            if (token == "+")
                s.push(a + b);

            else if (token == "-")
                s.push(a - b);

            else if (token == "*")
                s.push(a * b);

            else if (token == "/")
                s.push(a / b);
        }
        else
        {
            // Convert operand into integer and PUSH
            s.push(stoi(token));
        }
    }

    // Final result will be at the top
    return s.pop();
}

int main()
{
    string expression = "5 6 2 + * 12 4 / -";

    cout << "Postfix Expression: " << expression << endl;

    int result = evaluatePostfix(expression);

    cout << "Final Result: " << result << endl;

    return 0;
}
