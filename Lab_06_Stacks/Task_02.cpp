#include <iostream>
using namespace std;

class Stack {
    string actions[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string action) {
        actions[++top] = action;
    }

    void pop() {
        if (top == -1)
            cout << "Stack is empty!" << endl;
        else
            top--;
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << actions[i] << endl;
        }
    }

    void showTop() {
        if (top == -1)
            cout << "No action available";
        else
            cout << actions[top] << endl;
    }
};

int main() {
    Stack s;

    s.push("Type Hello");
    s.push("Type World");
    s.push("Add !");
    s.push("Delete !");

    cout << "Actions (TOP to Bottom):" << endl;
    s.display();

    cout << "\nUndo Two Actions (POP):" << endl;
    s.pop();
    s.pop();

    cout << "\nCurrent TOP Action: ";
    s.showTop();

    cout << "\nRemaining Actions:" << endl;
    s.display();

    return 0;
}