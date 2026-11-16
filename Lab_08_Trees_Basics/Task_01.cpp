#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node *left, *right;

    Node(string n) {
        name = n;
        left = right = NULL;
    }
};

int main() {
    Node *root = new Node("Grandfather");

    root->left = new Node("Father");
    root->right = new Node("Uncle");

    root->left->left = new Node("Ali");
    root->left->right = new Node("Ahmed");

    root->right->left = new Node("Sara");
    root->right->right = new Node("Ayesha");

    cout << root->name << " -> Left: " << root->left->name
         << ", Right: " << root->right->name << endl;

    cout << root->left->name << " -> Left: " << root->left->left->name
         << ", Right: " << root->left->right->name << endl;

    cout << root->right->name << " -> Left: " << root->right->left->name
         << ", Right: " << root->right->right->name << endl;

    return 0;
}