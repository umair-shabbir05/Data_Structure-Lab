#include <iostream>
using namespace std;

class Node {
public:
    string id;
    Node* next;

    Node(string order) {
        id = order;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
        } else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        Node* temp = top;

        while (temp != NULL) {
            cout << temp->id << endl;
            temp = temp->next;
        }
    }

    void showTop() {
        if (top == NULL)
            cout << "No order available" << endl;
        else
            cout << top->id << endl;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack s;

    s.push("ORD-101");
    s.push("ORD-102");
    s.push("ORD-103");
    s.push("ORD-104");

    cout << "Orders (TOP to Bottom):" << endl;
    s.display();

    cout << "\nProcessing Two Orders (POP):" << endl;
    s.pop();
    s.pop();

    cout << "\nCurrent TOP Order: ";
    s.showTop();

    cout << "\nRemaining Orders:" << endl;
    s.display();

    cout << "\nIs Stack Empty? ";
    if (s.isEmpty())
        cout << "Yes";
    else
        cout << "No";

    return 0;
}