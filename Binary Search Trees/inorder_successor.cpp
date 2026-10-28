#include <iostream>
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

Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) { //left subtree
        root->left = insert(root->left, val);
    } else { //right subtree
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;

    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

Node* getInorderSuccessor(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    while(root->left != NULL) {
        root = root->left;
    }

    return root; //IS
}

int main() {
    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node* root = buildBST(arr2, 9);

    Node* IS = getInorderSuccessor(root->right);

    if(IS != NULL) {
        cout << IS->data << endl;
    }

    return 0;
}