#include <iostream>
#include <vector>
#include <algorithm>
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

int count(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount + rightCount + 1;
}

int sum(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return leftSum + rightSum + root->data;
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    idx = -1;
    Node* root = buildTree(nodes);

    cout << "count of nodes: " << count(root) << endl;
    cout << "sum of nodes: " << sum(root) << endl;
    cout << "height: " << height(root) << endl;
    return 0;
}
