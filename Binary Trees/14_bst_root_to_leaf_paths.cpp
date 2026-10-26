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

void printPath(vector<int> path) {
    cout << " path : ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void pathHelper(Node* root, vector<int>& path) {
    if (root == NULL) {
        return;
    }
    path.push_back(root->data);

    if (root->left == NULL && root->right == NULL) { //leaf
        printPath(path);
        path.pop_back();
        return;
    }

    pathHelper(root->left, path);
    pathHelper(root->right, path);
    path.pop_back();
}

void rootToLeafPath(Node* root) {
    vector<int> path;
    pathHelper(root, path);
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);
    rootToLeafPath(root);
    return 0;
}
