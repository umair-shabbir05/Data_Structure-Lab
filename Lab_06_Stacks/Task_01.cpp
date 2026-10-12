#include <iostream>
using namespace std;

class Stack {
    string pages[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string page) {
        pages[++top] = page;
    }

    void pop() {
        if (top == -1)
            cout << "Stack is empty!";
        else
            top--;
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }

    void showTop() {
        if (top == -1)
            cout << "No page available";
        else
            cout << pages[top] << endl;
    }
};

int main() {
    Stack s;

    s.push("Google");
    s.push("YouTube");
    s.push("Facebook");
    s.push("GitHub");

    cout << "Browsing History (TOP to Bottom):" << endl;
    s.display();

    cout << "\nPress Back (POP):" << endl;
    s.pop();

    cout << "\nCurrent TOP Page: ";
    s.showTop();

    cout << "\nRemaining Browsing History:" << endl;
    s.display();

    return 0;
}