#include <iostream>
using namespace std;

// Node class
class Node {
public:
    string image;
    Node* prev;
    Node* next;

    Node(string name) {
        image = name;
        prev = NULL;
        next = NULL;
    }
};

// Doubly Linked List class
class Gallery {
private:
    Node* head;
    Node* tail;

public:
    Gallery() {
        head = NULL;
        tail = NULL;
    }

    // Add image
    void addImage(string name) {
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

        cout << "Images (First -> Last):\n";

        while (temp != NULL) {
            cout << temp->image << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Display last to first
    void displayBackward() {
        Node* temp = tail;

        cout << "\nImages (Last -> First):\n";

        while (temp != NULL) {
            cout << temp->image << " -> ";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }
};

int main() {
    Gallery gallery;

    // Store 5 images
    gallery.addImage("Photo1.jpg");
    gallery.addImage("Photo2.jpg");
    gallery.addImage("Photo3.jpg");
    gallery.addImage("Photo4.jpg");
    gallery.addImage("Photo5.jpg");

    // Display images
    gallery.displayForward();
    gallery.displayBackward();

    return 0;
}
