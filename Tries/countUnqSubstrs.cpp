//count the total number of distinct substrings of a given string using a trie.
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string key) { //O(L)
        Node* temp = root;

        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node(); //insert
            }
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }

    int countHelper(Node* root) {
        int ans = 0;

        for(pair<char, Node*> child : root->children) {
            ans += countHelper(child.second);
        }

        return ans + 1;
    }

    int countNodes() {
        return countHelper(root);
    }
};

int countUniqueSubstr(string str) {
    Trie trie;

    //find suffix
    for(int i=0; i<str.size(); i++) {
        string suffix = str.substr(i);
        trie.insert(suffix);
    }

    return trie.countNodes();
}

int main() {
    string str = "ababa";

    cout << countUniqueSubstr(str) << endl;

    return 0;
}
