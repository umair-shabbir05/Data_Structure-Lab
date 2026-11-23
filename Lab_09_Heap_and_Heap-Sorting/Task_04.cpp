
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Name: Umair Shabbir
// Registration ID: 2502027
// Task 4: Hospital Medicine Expiry Management (Min Heap)

// Medicine Node
class Medicine
{
public:
    string name;
    int medicineID;
    int expiryDate;

    Medicine* left;
    Medicine* right;

    Medicine(string n, int id, int date)
    {
        name = n;
        medicineID = id;
        expiryDate = date;
        left = right = NULL;
    }
};

// Min Heap Class
class MinHeap
{
private:
    Medicine* root;

    // Swap medicine data
    void swapData(Medicine* a, Medicine* b)
    {
        swap(a->name, b->name);
        swap(a->medicineID, b->medicineID);
        swap(a->expiryDate, b->expiryDate);
    }

    // Heapify Up
    void heapifyUp(Medicine* child)
    {
        while (child != root)
        {
            Medicine* parent = NULL;
            queue<Medicine*> q;
            q.push(root);

            // Find parent of child
            while (!q.empty())
            {
                Medicine* temp = q.front();
                q.pop();

                if (temp->left == child || temp->right == child)
                {
                    parent = temp;
                    break;
                }

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            // Smaller expiry date moves towards root
            if (parent->expiryDate > child->expiryDate)
            {
                swapData(parent, child);
                child = parent;
            }
            else
                break;
        }
    }

    // Heapify Down
    void heapifyDown(Medicine* temp)
    {
        if (temp == NULL)
            return;

        Medicine* smallest = temp;

        if (temp->left != NULL &&
            temp->left->expiryDate < smallest->expiryDate)
        {
            smallest = temp->left;
        }

        if (temp->right != NULL &&
            temp->right->expiryDate < smallest->expiryDate)
        {
            smallest = temp->right;
        }

        if (smallest != temp)
        {
            swapData(temp, smallest);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap()
    {
        root = NULL;
    }

    // Insert Medicine
    void insert(string name, int id, int date)
    {
        Medicine* newNode = new Medicine(name, id, date);

        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            queue<Medicine*> q;
            q.push(root);

            // Insert at first available position
            while (!q.empty())
            {
                Medicine* temp = q.front();
                q.pop();

                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    break;
                }
                else
                    q.push(temp->left);

                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    break;
                }
                else
                    q.push(temp->right);
            }
        }

        // Apply Heapify Up
        heapifyUp(newNode);
    }

    // Display Heap using Level Order
    void display()
    {
        if (root == NULL)
        {
            cout << "No medicines available!" << endl;
            return;
        }

        queue<Medicine*> q;
        q.push(root);

        while (!q.empty())
        {
            Medicine* temp = q.front();
            q.pop();

            cout << "Medicine Name: " << temp->name
                 << ", Medicine ID: " << temp->medicineID
                 << ", Expiry Date: " << temp->expiryDate << endl;

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }

    // Delete Medicine with Nearest Expiry
    void deleteMin()
    {
        if (root == NULL)
        {
            cout << "No medicines available!" << endl;
            return;
        }

        cout << "\nMedicine with nearest expiry:\n";
        cout << "Name: " << root->name << endl;
        cout << "Medicine ID: " << root->medicineID << endl;
        cout << "Expiry Date: " << root->expiryDate << endl;

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return;
        }

        queue<Medicine*> q;
        q.push(root);

        Medicine* last = NULL;
        Medicine* parent = NULL;

        // Find last node and its parent
        while (!q.empty())
        {
            Medicine* temp = q.front();
            q.pop();

            if (temp->left)
            {
                parent = temp;
                last = temp->left;
                q.push(temp->left);
            }

            if (temp->right)
            {
                parent = temp;
                last = temp->right;
                q.push(temp->right);
            }
        }

        // Replace root data with last node data
        root->name = last->name;
        root->medicineID = last->medicineID;
        root->expiryDate = last->expiryDate;

        // Remove last node
        if (parent->right == last)
            parent->right = NULL;
        else
            parent->left = NULL;

        delete last;

        // Apply Heapify Down
        heapifyDown(root);
    }
};

// Main Function
int main()
{
    MinHeap h;

    // Insert six medicines
    h.insert("Panadol", 101, 20270115);
    h.insert("Brufen", 102, 20261210);
    h.insert("Augmentin", 103, 20280320);
    h.insert("Calpol", 104, 20261125);
    h.insert("Disprin", 105, 20270615);
    h.insert("Flagyl", 106, 20260510);

    cout << "Hospital Medicine Expiry Management\n";

    // Display original heap
    cout << "\nMedicines (Level Order Traversal):\n";
    h.display();

    // Delete medicine with nearest expiry
    h.deleteMin();

    // Display updated heap
    cout << "\nUpdated Min Heap:\n";
    h.display();

    return 0;
}

