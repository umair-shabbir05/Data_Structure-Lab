#include <iostream>
using namespace std;

// Node class
class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name) {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

// Doubly Linked List class
class BrowserHistory {
private:
    Node* head;
    Node* tail;

public:
    BrowserHistory() {
        head = NULL;
        tail = NULL;
    }

    // Add website
    void addWebsite(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display first to last
    void displayForward() {
        Node* temp = head;

        cout << "\nHistory (First -> Last):\n";

        while (temp != NULL) {
            cout << temp->website << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Display last to first
    void displayReverse() {
        Node* temp = tail;

        cout << "\nHistory (Last -> First):\n";

        while (temp != NULL) {
            cout << temp->website << " -> ";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }
};

int main() {
    BrowserHistory history;

    // Add 5 websites
    history.addWebsite("Google.com");
    history.addWebsite("YouTube.com");
    history.addWebsite("Facebook.com");
    history.addWebsite("Wikipedia.org");
    history.addWebsite("GitHub.com");

    // Display history
    history.displayForward();
    history.displayReverse();

    return 0;
}
