
#include <iostream>
#include <queue>
using namespace std;

int main() {

    //a pair stores two values together. here we are using a string and an integer
    //the default priority queue compares pairs lexicographically
    //first by first, then second if the first values are equal
    priority_queue<pair<string, int>> pq;

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
