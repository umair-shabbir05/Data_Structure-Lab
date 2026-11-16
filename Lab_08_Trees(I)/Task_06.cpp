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
        else
            cout << "Duplicate ID not allowed\n";

        return r;
    }

    bool search(Node *r, int x) {
        if (r == NULL) return false;
        if (r->data == x) return true;

        if (x < r->data)
            return search(r->left, x);

        return search(r->right, x);
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

            if (r->right == NULL) {
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

    void destroy(Node *r) {
        if (r == NULL) return;
        destroy(r->left);
        destroy(r->right);
        delete r;
    }

    ~BST() {
        destroy(root);
    }
};

int main() {
    BST t;
    int choice, id;

    do {
        cout << "\n\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Delete";
        cout << "\n4. In-order";
        cout << "\n5. Pre-order";
        cout << "\n6. Post-order";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter product ID: ";
            cin >> id;
            t.root = t.insert(t.root, id);
            break;

        case 2:
            cout << "Enter product ID to search: ";
            cin >> id;

            if (t.search(t.root, id))
                cout << "Product Found";
            else
                cout << "Product Not Found";
            break;

        case 3:
            cout << "Enter product ID to delete: ";
            cin >> id;

            if (t.search(t.root, id)) {
                t.root = t.deleteNode(t.root, id);
                cout << "Product Deleted";
            } else {
                cout << "Product Not Found";
            }
            break;

        case 4:
            cout << "In-order: ";
            t.inorder(t.root);
            break;

        case 5:
            cout << "Pre-order: ";
            t.preorder(t.root);
            break;

        case 6:
            cout << "Post-order: ";
            t.postorder(t.root);
            break;

        case 7:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 7);

    return 0;
}