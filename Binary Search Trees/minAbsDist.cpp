
#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

Node *buildBST(int arr[], int n)
{
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}

int minDist(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    // Initially, consider the current node the closest.
    int closest = root->data;

    // ITERATIVE VERSION
    while (root != NULL)
    {
        // Update closest if the current node is nearer to k
        if (abs(root->data - k) < abs(closest - k))
        {
            closest = root->data;
        }

        // Exact match: distance is zero
        if (root->data == k)
        {
            return root->data;
        }

        // Use the BST property to choose the next subtree
        if (k < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    // RECURSIVE VERSION
    //  if (k < root->data) {
    //      int leftAns = minDist(root->left, k);

    //     if (leftAns != -1 &&
    //         abs(leftAns - k) < abs(closest - k)) {
    //         closest = leftAns;
    //     }
    // } else {
    //     int rightAns = minDist(root->right, k);

    //     if (rightAns != -1 &&
    //         abs(rightAns - k) < abs(closest - k)) {
    //         closest = rightAns;
    //     }
    // }

    return closest;
}

int main()
{
    int arr[6] = {5, 1, 3, 4, 2, 7};

    Node *root = buildBST(arr, 6);

    int k = 6;

    cout << "Closest value to " << k
         << " is " << minDist(root, k) << endl;

    return 0;
}
