
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Node class
class Node {
public:
    string category;
    Node* left;
    Node* right;

    // Constructor
    Node(string name) {
        category = name;
        left = NULL;
        right = NULL;
    }
};

// BFS Traversal Function
void BFS(Node* root) {

    if (root == NULL)
        return;

    // Create a queue
    queue<Node*> q;

    // Insert root into queue
    q.push(root);

    cout << "Product Categories (BFS Traversal):\n";

    while (!q.empty()) {

        // Get front node
        Node* current = q.front();
        q.pop();

        // Display category
        cout << current->category << endl;

        // Insert left child
        if (current->left != NULL) {
            q.push(current->left);
        }

        // Insert right child
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {

    // Creating seven category nodes
    Node* root = new Node("Electronics");

    Node* c1 = new Node("Clothing");
    Node* c2 = new Node("Mobiles");

    Node* c3 = new Node("Laptops");
    Node* c4 = new Node("Men");
    Node* c5 = new Node("Women");
    Node* c6 = new Node("Accessories");

    // Connecting nodes
    root->left = c1;
    root->right = c2;

    c1->left = c3;
    c1->right = c4;

    c2->left = c5;
    c2->right = c6;

    // Perform BFS Traversal
    BFS(root);

    return 0;
}
