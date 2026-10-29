#include <iostream>
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
    { // left subtree
        root->left = insert(root->left, val);
    }
    else
    { // right subtree
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

int rangeSum(Node *root, int low, int high)
{
   if (root == NULL)
    {
        return 0;
    }

    if (root->data < low)
    {
        return rangeSum(root->right, low, high);
    }
    else if (root->data > high)
    {
        return rangeSum(root->left, low, high);
    }
    else
    {
        return root->data
             + rangeSum(root->left, low, high)
             + rangeSum(root->right, low, high);
    }
}

int main()
{
    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node *root = buildBST(arr2, 9);

    int l = 5;
    int h = 12;
    int sum = rangeSum(root, l,h);
    cout << "sum from "<<l<<" to "<< h<<" is "<<sum << endl;

    return 0;
}