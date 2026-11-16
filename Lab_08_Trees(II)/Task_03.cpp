
#include <iostream>
using namespace std;

// Node class
class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string name) {
        folder = name;
        left = NULL;
        right = NULL;
    }
};

// In-order Traversal (Left, Root, Right)
void inOrder(Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->folder << " ";
    inOrder(root->right);
}

// Pre-order Traversal (Root, Left, Right)
void preOrder(Node* root) {
    if (root == NULL)
        return;

    cout << root->folder << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Post-order Traversal (Left, Right, Root)
void postOrder(Node* root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->folder << " ";
}

int main() {

    // Creating the binary tree
    Node* root = new Node("Computer");

    root->left = new Node("Documents");
    root->right = new Node("Pictures");

    root->left->left = new Node("Assignments");
    root->left->right = new Node("Projects");

    root->right->left = new Node("Family");
    root->right->right = new Node("Vacation");

    // Display In-order Traversal
    cout << "In-order Traversal: ";
    inOrder(root);

    // Display Pre-order Traversal
    cout << "\nPre-order Traversal: ";
    preOrder(root);

    // Display Post-order Traversal
    cout << "\nPost-order Traversal: ";
    postOrder(root);

    return 0;
}
