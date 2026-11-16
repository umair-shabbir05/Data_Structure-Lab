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

    void inorder(Node *r) {
        if (r == NULL) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }

    void preorder(Node *r) {
        if (r == NULL) return;
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }

    void postorder(Node *r) {
        if (r == NULL) return;
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
};

int main() {
    BST t;
    int a[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        t.root = t.insert(t.root, a[i]);

    cout << "In-order: ";
    t.inorder(t.root);

    cout << "\nPre-order: ";
    t.preorder(t.root);

    cout << "\nPost-order: ";
    t.postorder(t.root);

    cout << "\nIn-order displays ascending order.";

    return 0;
}