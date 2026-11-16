
#include <iostream>
using namespace std;

// Node class
class Node {
public:
    string name;
    Node* left;
    Node* right;

    // Constructor
    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

int main() {

    // Creating root node (HOD)
    Node* root = new Node("Dr. Ahmed (HOD)");

    // Creating child nodes
    root->left = new Node("Mr. Ali (Coordinator)");
    root->right = new Node("Dr. Sara (Coordinator)");

    // Creating faculty members
    root->left->left = new Node("Mr. Usman (Faculty)");
    root->left->right = new Node("Ms. Ayesha (Faculty)");

    root->right->left = new Node("Mr. Bilal (Faculty)");
    root->right->right = new Node("Ms. Fatima (Faculty)");

    // Display department hierarchy
    cout << "University Department Hierarchy\n\n";

    cout << "Member: " << root->name << endl;
    cout << "Left Child: " << root->left->name << endl;
    cout << "Right Child: " << root->right->name << endl;

    cout << "\nMember: " << root->left->name << endl;
    cout << "Left Child: " << root->left->left->name << endl;
    cout << "Right Child: " << root->left->right->name << endl;

    cout << "\nMember: " << root->right->name << endl;
    cout << "Left Child: " << root->right->left->name << endl;
    cout << "Right Child: " << root->right->right->name << endl;

    cout << "\nMember: " << root->left->left->name << endl;
    cout << "Left Child: None" << endl;
    cout << "Right Child: None" << endl;

    cout << "\nMember: " << root->left->right->name << endl;
    cout << "Left Child: None" << endl;
    cout << "Right Child: None" << endl;

    cout << "\nMember: " << root->right->left->name << endl;
    cout << "Left Child: None" << endl;
    cout << "Right Child: None" << endl;

    cout << "\nMember: " << root->right->right->name << endl;
    cout << "Left Child: None" << endl;
    cout << "Right Child: None" << endl;

    return 0;
}
