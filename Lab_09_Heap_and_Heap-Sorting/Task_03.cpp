
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Name: Umair Shabbir
// Registration ID: 2502027
// Task 3: Online Shopping Order Sorting (Heap Sort)

// Order Node
class Order
{
public:
    int orderID;
    string customerName;
    int amount;

    Order* left;
    Order* right;

    Order(int id, string name, int a)
    {
        orderID = id;
        customerName = name;
        amount = a;
        left = right = NULL;
    }
};

// Max Heap Class
class MaxHeap
{
private:
    Order* root;

    // Swap order data
    void swapData(Order* a, Order* b)
    {
        swap(a->orderID, b->orderID);
        swap(a->customerName, b->customerName);
        swap(a->amount, b->amount);
    }

    // Heapify Up
    void heapifyUp(Order* child)
    {
        while (child != root)
        {
            Order* parent = NULL;
            queue<Order*> q;
            q.push(root);

            // Find parent of child
            while (!q.empty())
            {
                Order* temp = q.front();
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

            if (parent->amount < child->amount)
            {
                swapData(parent, child);
                child = parent;
            }
            else
                break;
        }
    }

    // Heapify Down
    void heapifyDown(Order* temp)
    {
        if (temp == NULL)
            return;

        Order* largest = temp;

        if (temp->left != NULL &&
            temp->left->amount > largest->amount)
        {
            largest = temp->left;
        }

        if (temp->right != NULL &&
            temp->right->amount > largest->amount)
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

    // Insert Order
    void insert(int id, string name, int amount)
    {
        Order* newNode = new Order(id, name, amount);

        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            queue<Order*> q;
            q.push(root);

            // Insert at first available position
            while (!q.empty())
            {
                Order* temp = q.front();
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

    // Delete root and return its amount
    int deleteMax()
    {
        if (root == NULL)
            return -1;

        int deletedAmount = root->amount;

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return deletedAmount;
        }

        queue<Order*> q;
        q.push(root);

        Order* last = NULL;
        Order* parent = NULL;

        // Find last node and its parent
        while (!q.empty())
        {
            Order* temp = q.front();
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
        root->orderID = last->orderID;
        root->customerName = last->customerName;
        root->amount = last->amount;

        // Remove last node
        if (parent->right == last)
            parent->right = NULL;
        else
            parent->left = NULL;

        delete last;

        // Apply Heapify Down
        heapifyDown(root);

        return deletedAmount;
    }

    // Heap Sort
    void heapSort()
    {
        vector<int> amounts;

        // Repeatedly delete maximum amount
        while (root != NULL)
        {
            amounts.push_back(deleteMax());
        }

        // Display in ascending order
        cout << "\nOrder Amounts in Ascending Order:\n";

        for (int i = amounts.size() - 1; i >= 0; i--)
        {
            cout << amounts[i] << " ";
        }

        cout << endl;
    }
};

// Main Function
int main()
{
    MaxHeap h;

    // Insert six orders
    h.insert(101, "Ali", 5000);
    h.insert(102, "Ahmed", 2500);
    h.insert(103, "Sara", 8000);
    h.insert(104, "Usman", 1500);
    h.insert(105, "Ayesha", 6000);
    h.insert(106, "Hamza", 3500);

    cout << "Online Shopping Order Sorting\n";

    // Apply Heap Sort
    h.heapSort();

    return 0;
}

