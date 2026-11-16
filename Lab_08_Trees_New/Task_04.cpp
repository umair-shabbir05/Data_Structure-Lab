
#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int token;
    int height;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        token = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

// Get height of node
int getHeight(Node* node) {
    if (node == NULL)
        return 0;

    return node->height;
}

// Calculate balance factor
int getBalance(Node* node) {
    if (node == NULL)
        return 0;

    return getHeight(node->left) -
           getHeight(node->right);
}

// Right Rotation (LL Case)
Node* rightRotate(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

// Left Rotation (RR Case)
Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

// Insert node into AVL Tree
Node* insert(Node* node, int value) {

    // Normal BST insertion
    if (node == NULL)
        return new Node(value);

    if (value < node->token)
        node->left = insert(node->left, value);

    else if (value > node->token)
        node->right = insert(node->right, value);

    else
        return node;

    // Update height
    node->height = 1 + max(getHeight(node->left),
                           getHeight(node->right));

    // Calculate balance factor
    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && value < node->left->token)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && value > node->right->token)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && value > node->left->token) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && value < node->right->token) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// In-order Traversal
void inOrder(Node* root) {

    if (root == NULL)
        return;

    inOrder(root->left);

    cout << root->token << " ";

    inOrder(root->right);
}

// Display tree structure
void displayTree(Node* root, int space = 0) {

    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->token << endl;

    displayTree(root->left, space);
}

// Main Function
int main() {

    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    cout << "HOSPITAL APPOINTMENT SYSTEM\n";
    cout << "===========================\n";

    // Insert appointment tokens
    for (int i = 0; i < 7; i++) {
        root = insert(root, tokens[i]);
    }

    // Display In-order Traversal
    cout << "\nIn-order Traversal:\n";

    inOrder(root);

    // Display final AVL Tree
    cout << "\n\nFinal Balanced AVL Tree:\n";

    displayTree(root);

    cout << endl;

    return 0;
}
