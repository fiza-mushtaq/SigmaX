#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildBST(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }
    Node* root = new Node(arr[0]);
    for (int i = 1; i < n; i++) {
        Node* curr = root;
        while (true) {
            if (arr[i] < curr->data) {
                if (curr->left == NULL) {
                    curr->left = new Node(arr[i]);
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right == NULL) {
                    curr->right = new Node(arr[i]);
                    break;
                }
                curr = curr->right;
            }
        }
    }
    return root;
}

void getInorder(Node* root, vector<int>& nodes) {
    if (root == NULL) {
        return;
    }
    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}

Node* BSTfromSortedVec(vector<int> arr, int st, int end) {
    if (st > end) {
        return NULL;
    }

    int mid = st + (end - st) / 2;
    Node* curr = new Node(arr[mid]);

    curr->left = BSTfromSortedVec(arr, st, mid - 1);
    curr->right = BSTfromSortedVec(arr, mid + 1, end);

    return curr;
}

Node* balanceBST(Node* root) {
    //get inorder seq
    vector<int> nodes;
    getInorder(root, nodes);

    return BSTfromSortedVec(nodes, 0, (int)nodes.size() - 1);
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* root = buildBST(arr, 9);
    Node* balancedRoot = balanceBST(root);
    preorder(balancedRoot);
    cout << endl;
    return 0;
}
