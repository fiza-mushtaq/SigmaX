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
{ // O(logn)
    if (root == NULL)
    {
        root = new Node(val);
        return root;
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

void inorder(Node *root, int k, int &count, int &ans)
{
    if (root == NULL || count >= k)
    { // Base Case, if there is no node stop this function
        return;
    }

    inorder(root->left, k, count, ans); // first visit the left subtree

    if (count >= k)
    {
        return;
    }
    count++; // we have finished visitng the left subtree now the current node is visited

    if (count == k)
    {
        ans = root->data;
        return;
    }
    inorder(root->right, k, count, ans);
}

int main()
{
    int arr[6] = {5, 1, 3, 4, 2, 7};
    // int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node *root = buildBST(arr, 6);

    int count = 0;
    int ans = -1;
    inorder(root, 3, count, ans);
    cout << ans << endl;

    return 0;
}