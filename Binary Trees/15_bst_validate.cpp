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

bool validateHelper(Node* root, Node* minNode, Node* maxNode) {
    if (root == NULL) {
        return true;
    }

    if (minNode != NULL && root->data <= minNode->data) {
        return false;
    }
    if (maxNode != NULL && root->data >= maxNode->data) {
        return false;
    }

    return validateHelper(root->left, minNode, root)
        && validateHelper(root->right, root, maxNode);
}

bool validateBST(Node* root) {
    return validateHelper(root, NULL, NULL);
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);
    cout << validateBST(root) << endl; //1
    return 0;
}
