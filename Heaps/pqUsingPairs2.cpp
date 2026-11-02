
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//here we compare the second value of each pair instead of first
struct ComparePair {
    bool operator() (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second > p2.second;   //creates a min heap based on the second value
    }                                   //p1.second < p2.second creates a max heap based on the second value
};

int main() {
    priority_queue<pair<string, int>,
                   vector<pair<string, int>>, ComparePair> pq;

    pq.push(make_pair("aman", 500));
    pq.push(make_pair("bhumika", 1000));
    pq.push(make_pair("chetan", 2000));

    while(!pq.empty()) {
        cout << "top = " << pq.top().first << ", "
             << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}
