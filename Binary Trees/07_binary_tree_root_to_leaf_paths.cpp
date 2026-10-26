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

static int idx = -1;

Node* buildTree(vector<int> nodes) {
    idx++;
    if (idx >= (int)nodes.size() || nodes[idx] == -1) {
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
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
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    idx = -1;
    Node* root = buildTree(nodes);
    rootToLeafPath(root);
    return 0;
}
