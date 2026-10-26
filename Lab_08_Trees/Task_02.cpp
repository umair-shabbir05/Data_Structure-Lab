#include <iostream>
using namespace std;

class BST {
public:
    struct Node {
        int data;
        Node *left, *right;

        Node(int x) {
            data = x;
            left = right = NULL;
        }
    };

    Node *root = NULL;

    Node* insert(Node *r, int x) {
        if (r == NULL)
            return new Node(x);

        if (x < r->data)
            r->left = insert(r->left, x);
        else if (x > r->data)
            r->right = insert(r->right, x);

        return r;
    }

    void display(Node *r) {
        if (r == NULL) return;
        display(r->left);
        cout << r->data << " ";
        display(r->right);
    }
};

int main() {
    BST t;
    int x;

    int a[] = {45, 25, 65, 15, 35, 55, 75};

    for (int i = 0; i < 7; i++)
        t.root = t.insert(t.root, a[i]);

    cout << "Enter two roll numbers: ";
    for (int i = 0; i < 2; i++) {
        cin >> x;
        t.root = t.insert(t.root, x);
    }

    cout << "Sorted roll numbers: ";
    t.display(t.root);

    return 0;
}