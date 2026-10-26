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

    Node* minimum(Node *r) {
        while (r->left != NULL)
            r = r->left;
        return r;
    }

    Node* deleteNode(Node *r, int x) {
        if (r == NULL) return NULL;

        if (x < r->data)
            r->left = deleteNode(r->left, x);
        else if (x > r->data)
            r->right = deleteNode(r->right, x);
        else {
            if (r->left == NULL) {
                Node *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) {
                Node *temp = r->left;
                delete r;
                return temp;
            }

            Node *temp = minimum(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
        }

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
    int a[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        t.root = t.insert(t.root, a[i]);

    int id;
    cout << "Enter employee ID to delete: ";
    cin >> id;

    t.root = t.deleteNode(t.root, id);

    cout << "Remaining IDs: ";
    t.display(t.root);

    return 0;
}