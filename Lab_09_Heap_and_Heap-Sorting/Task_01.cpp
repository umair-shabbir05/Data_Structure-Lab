
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Name: Umair Shabbir
// Registration ID: 2502027
// Task 1: University Student Merit Ranking (Max Heap)

// Student Node
class Student
{
public:
    string name;
    int rollNo;
    int marks;

    Student* left;
    Student* right;

    Student(string n, int r, int m)
    {
        name = n;
        rollNo = r;
        marks = m;
        left = right = NULL;
    }
};

// Max Heap Class
class MaxHeap
{
private:
    Student* root;

    // Swap student data
    void swapData(Student* a, Student* b)
    {
        swap(a->name, b->name);
        swap(a->rollNo, b->rollNo);
        swap(a->marks, b->marks);
    }

    // Heapify Up
    void heapifyUp()
    {
        Student* child = root;
        queue<Student*> q;
        q.push(root);

        // Find the last inserted node
        while (!q.empty())
        {
            Student* temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);

            child = temp;
        }

        // Move greater marks towards root
        while (child != root)
        {
            Student* parent = NULL;
            queue<Student*> q2;
            q2.push(root);

            // Find parent of child
            while (!q2.empty())
            {
                Student* temp = q2.front();
                q2.pop();

                if (temp->left == child || temp->right == child)
                {
                    parent = temp;
                    break;
                }

                if (temp->left)
                    q2.push(temp->left);

                if (temp->right)
                    q2.push(temp->right);
            }

            if (parent->marks < child->marks)
                swapData(parent, child);
            else
                break;

            child = parent;
        }
    }

public:
    MaxHeap()
    {
        root = NULL;
    }

    // Insert student
    void insert(string name, int roll, int marks)
    {
        Student* newNode = new Student(name, roll, marks);

        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            queue<Student*> q;
            q.push(root);

            // Insert at first available position
            while (!q.empty())
            {
                Student* temp = q.front();
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

        heapifyUp();
    }

    // Display Heap using Level Order
    void display()
    {
        if (root == NULL)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        queue<Student*> q;
        q.push(root);

        while (!q.empty())
        {
            Student* temp = q.front();
            q.pop();

            cout << "Name: " << temp->name
                 << ", Roll No: " << temp->rollNo
                 << ", Marks: " << temp->marks << endl;

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }

    // Delete student with highest marks
    void deleteMax()
    {
        if (root == NULL)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "\nDeleted Student: "
             << root->name << " (Marks: "
             << root->marks << ")" << endl;

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return;
        }

        queue<Student*> q;
        q.push(root);

        Student* last = NULL;
        Student* parent = NULL;

        // Find last node and its parent
        while (!q.empty())
        {
            Student* temp = q.front();
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
        root->rollNo = last->rollNo;
        root->marks = last->marks;

        // Remove last node
        if (parent->right == last)
            parent->right = NULL;
        else
            parent->left = NULL;

        delete last;

        // Heapify Down
        heapifyDown(root);
    }

    // Heapify Down
    void heapifyDown(Student* temp)
    {
        if (temp == NULL)
            return;

        Student* largest = temp;

        if (temp->left != NULL &&
            temp->left->marks > largest->marks)
        {
            largest = temp->left;
        }

        if (temp->right != NULL &&
            temp->right->marks > largest->marks)
        {
            largest = temp->right;
        }

        if (largest != temp)
        {
            swapData(temp, largest);
            heapifyDown(largest);
        }
    }
};

// Main Function
int main()
{
    MaxHeap h;

    // Insert six students
    h.insert("Ali", 101, 85);
    h.insert("Ahmed", 102, 92);
    h.insert("Sara", 103, 95);
    h.insert("Usman", 104, 78);
    h.insert("Ayesha", 105, 89);
    h.insert("Hamza", 106, 98);

    // Display original heap
    cout << "University Student Merit Ranking" << endl;
    cout << "\nMax Heap (Level Order Traversal):\n";
    h.display();

    // Delete student with highest marks
    h.deleteMax();

    // Display updated heap
    cout << "\nUpdated Max Heap:\n";
    h.display();

    return 0;
}

