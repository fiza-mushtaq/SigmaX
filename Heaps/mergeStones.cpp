
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int mergeStones(vector<int> stones) {
    priority_queue<int, vector<int>, greater<int>> pq(stones.begin(), stones.end());

    int cost = 0;

    while(pq.size() > 1) {
        int min1 = pq.top();
        pq.pop();

        int min2 = pq.top();
        pq.pop();

        int sum = min1 + min2;

        cost += sum;
        pq.push(sum);
    }

    cout << "min cost = " << cost << endl;
    return cost;
}

int main() {
    vector<int> stones = {4, 3, 2, 6};

    mergeStones(stones);

    return 0;
}
