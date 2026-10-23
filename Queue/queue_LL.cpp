
#include <iostream>
using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

public:
    Queue() {
        head = tail = NULL;
    }

    void push(int data) {
        Node* newNode = new Node(data);

        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL) {
            tail = NULL;
        }
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        return head->data;
    }

    bool empty() {
        return head == NULL;
    }

    ~Queue() {
        while (!empty()) {
            pop();
        }
    }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
