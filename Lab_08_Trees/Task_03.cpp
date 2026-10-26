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
        if (r == NULL) return new Node(x);

        if (x < r->data)
            r->left = insert(r->left, x);
        else if (x > r->data)
            r->right = insert(r->right, x);

        return r;
    }

    void search(int x) {
        Node *r = root;
        int count = 0;

        while (r != NULL) {
            count++;

            if (r->data == x) {
                cout << "Book Found\n";
                cout << "Comparisons: " << count;
                return;
            }

            if (x < r->data)
                r = r->left;
            else
                r = r->right;
        }

        cout << "Book Not Found\n";
        cout << "Comparisons: " << count;
    }
};

int main() {
    BST t;
    int a[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        t.root = t.insert(t.root, a[i]);

    int id;
    cout << "Enter book ID: ";
    cin >> id;

    t.search(id);

    return 0;
}