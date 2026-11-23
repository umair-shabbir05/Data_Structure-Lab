
#include <iostream>
using namespace std;

// Name: Umair Shabbir
// Reg. ID: 2502027
// Task No: 01
// Problem: Balanced Parentheses using Array Stack

const int SIZE = 100;

// Stack class using array
class Stack
{
private:
    char arr[SIZE];
    int top;

public:
    // Constructor
    Stack()
    {
        top = -1;
    }

    // PUSH operation
    void push(char ch)
    {
        if (top == SIZE - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }

        top++;
        arr[top] = ch;
    }

    // POP operation
    char pop()
    {
        if (top == -1)
        {
            return '\0';
        }

        char ch = arr[top];
        top--;
        return ch;
    }

    // TOP operation
    char TOP()
    {
        if (top == -1)
        {
            return '\0';
        }

        return arr[top];
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return top == -1;
    }
};

// Function to check balanced parentheses
bool isBalanced(string expression)
{
    Stack s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        // Push opening brackets into stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }

        // Check closing brackets
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // No opening bracket available
            if (s.isEmpty())
            {
                return false;
            }

            // Get the top opening bracket
            char topBracket = s.TOP();

            // Check whether brackets match
            if ((ch == ')' && topBracket == '(') ||
                (ch == '}' && topBracket == '{') ||
                (ch == ']' && topBracket == '['))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    // Stack must be empty at the end
    return s.isEmpty();
}

int main()
{
    string expression = "{[()]}";

    cout << "Expression: " << expression << endl;

    if (isBalanced(expression))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
