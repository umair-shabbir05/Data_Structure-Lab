
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Name: Umair Shabbir
// Registration ID: 2502027
// Task 2: Hospital Emergency Management System (Max Heap)

// Patient Node
class Patient
{
public:
    string name;
    int patientID;
    int priority;

    Patient* left;
    Patient* right;

    Patient(string n, int id, int p)
    {
        name = n;
        patientID = id;
        priority = p;
        left = right = NULL;
    }
};

// Max Heap Class
class MaxHeap
{
private:
    Patient* root;

    // Swap patient data
    void swapData(Patient* a, Patient* b)
    {
        swap(a->name, b->name);
        swap(a->patientID, b->patientID);
        swap(a->priority, b->priority);
    }

    // Heapify Up
    void heapifyUp(Patient* child)
    {
        while (child != root)
        {
            Patient* parent = NULL;
            queue<Patient*> q;
            q.push(root);

            // Find parent of child
            while (!q.empty())
            {
                Patient* temp = q.front();
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

            if (parent->priority < child->priority)
            {
                swapData(parent, child);
                child = parent;
            }
            else
                break;
        }
    }

    // Heapify Down
    void heapifyDown(Patient* temp)
    {
        if (temp == NULL)
            return;

        Patient* largest = temp;

        if (temp->left != NULL &&
            temp->left->priority > largest->priority)
        {
            largest = temp->left;
        }

        if (temp->right != NULL &&
            temp->right->priority > largest->priority)
        {
            largest = temp->right;
        }

        if (largest != temp)
        {
            swapData(temp, largest);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap()
    {
        root = NULL;
    }

    // Insert Patient
    void insert(string name, int id, int priority)
    {
        Patient* newNode = new Patient(name, id, priority);

        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            queue<Patient*> q;
            q.push(root);

            // Insert at first available position
            while (!q.empty())
            {
                Patient* temp = q.front();
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

    // Display Patients using Level Order
    void display()
    {
        if (root == NULL)
        {
            cout << "No patients in the heap!" << endl;
            return;
        }

        queue<Patient*> q;
        q.push(root);

        while (!q.empty())
        {
            Patient* temp = q.front();
            q.pop();

            cout << "Name: " << temp->name
                 << ", Patient ID: " << temp->patientID
                 << ", Priority: " << temp->priority << endl;

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }

    // Display Patient with Highest Priority
    void highestPriority()
    {
        if (root == NULL)
        {
            cout << "No patients available!" << endl;
            return;
        }

        cout << "\nPatient to be treated first:\n";
        cout << "Name: " << root->name << endl;
        cout << "Patient ID: " << root->patientID << endl;
        cout << "Priority: " << root->priority << endl;
    }

    // Delete Patient with Highest Priority
    void deleteMax()
    {
        if (root == NULL)
        {
            cout << "No patients to delete!" << endl;
            return;
        }

        cout << "\nPatient treated: "
             << root->name << endl;

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return;
        }

        queue<Patient*> q;
        q.push(root);

        Patient* last = NULL;
        Patient* parent = NULL;

        // Find last node and its parent
        while (!q.empty())
        {
            Patient* temp = q.front();
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
        root->patientID = last->patientID;
        root->priority = last->priority;

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
    MaxHeap h;

    // Insert six patients
    h.insert("Ali", 101, 3);
    h.insert("Ahmed", 102, 8);
    h.insert("Sara", 103, 5);
    h.insert("Usman", 104, 9);
    h.insert("Ayesha", 105, 6);
    h.insert("Hamza", 106, 7);

    // Display all patients
    cout << "Hospital Emergency Management System\n";
    cout << "\nAll Patients (Level Order):\n";
    h.display();

    // Identify highest priority patient
    h.highestPriority();

    // Delete patient after treatment
    h.deleteMax();

    // Display updated heap
    cout << "\nUpdated Patient Heap:\n";
    h.display();

    // Display next patient
    h.highestPriority();

    return 0;
}

