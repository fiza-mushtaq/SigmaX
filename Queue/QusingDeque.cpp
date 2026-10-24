
#include <iostream>
#include <deque>
using namespace std;

class Queue {
    deque<int> deq;

public:
    void push(int data) {
        deq.push_back(data);
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }

        deq.pop_front();
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        return deq.front();
    }

    bool empty() {
        return deq.empty();
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
