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

void printInRange(Node* root, int start, int end) {
    if (root == NULL) {
        return;
    }

    if (start <= root->data && root->data <= end) { //case1
        cout << root->data << " ";
        printInRange(root->left, start, end);
        printInRange(root->right, start, end);
    } else if (root->data < start) { //case2
        printInRange(root->right, start, end);
    } else { //case3
        printInRange(root->left, start, end);
    }
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);
    printInRange(root, 4, 10);
    cout << endl;
    return 0;
}
