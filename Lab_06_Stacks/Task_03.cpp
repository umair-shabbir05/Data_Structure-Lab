#include <iostream>
using namespace std;

class Node {
public:
    string id;
    Node* next;

    Node(string patient) {
        id = patient;
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
            cout << "No request available";
        else
            cout << top->id << endl;
    }
};

int main() {
    Stack s;

    s.push("P101");
    s.push("P102");
    s.push("P103");
    s.push("P104");

    cout << "Requests (TOP to Bottom):" << endl;
    s.display();

    cout << "\nPOP: Handling Latest Request" << endl;
    s.pop();

    cout << "\nNew TOP Request: ";
    s.showTop();

    cout << "\nRemaining Requests:" << endl;
    s.display();

    return 0;
}