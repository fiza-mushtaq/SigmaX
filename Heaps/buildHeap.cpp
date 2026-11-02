
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Heap {

    //building a heap from scratch using a vector
    vector<int> vec; //CBT

public:

    void push(int val) {
        //step1
        vec.push_back(val);

        //fix heap
        int x = vec.size()-1; //childI
        int parI = (x-1)/2;

        while(parI >= 0 && vec[x] > vec[parI]) {
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }

    void pop() {
        //step1
        swap(vec[0], vec[vec.size()-1]);

        //step2
        vec.pop_back();

        //step3
        if(!vec.empty()) {
            heapify(0);
        }
    }

    int top() { //O(1)
        return vec[0]; //highest priority element
    }

    bool empty() {
        return vec.size() == 0;
    }

    void heapify(int i) { //i = parI
        if(i >= vec.size()) {
            return;
        }

        int l = 2*i + 1;
        int r = 2*i + 2;

        int maxI = i;

        if(l < vec.size() && vec[l] > vec[maxI]) {
            maxI = l;
        }

        if(r < vec.size() && vec[r] > vec[maxI]) {
            maxI = r;
        }

        swap(vec[i], vec[maxI]);

        if(maxI != i) { //swapping with child node
            heapify(maxI);
        }
    }
};

int main() {
    Heap h;

    h.push(5);
    h.push(10);
    h.push(9);
    h.push(7);
    h.push(3);

    while(!h.empty()) {
        cout << h.top() << endl;
        h.pop();
    }

    return 0;
}
