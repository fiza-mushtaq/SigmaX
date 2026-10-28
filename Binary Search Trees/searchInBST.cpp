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

bool search(Node* root, int key) {
    if(root == NULL) {
        return false;
    }

    if(root->data == key) { //FOUND
        return true;
    }

    if(root->data > key) { //left subtree
        return search(root->left, key);
    } else {
        return search(root->right, key); //right subtree
    }
}

int main() {
    //int arr[6] = {5, 1, 3, 4, 2, 7}; //1 2 3 4 5 7
    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node* root = buildBST(arr2, 9);

    cout << search(root, 6) << endl;

    return 0;
}