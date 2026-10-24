
#include <iostream>
#include <queue>
#include <string>
using namespace std;

void FirstNonRepeat(string str) {
    queue<char> q;
    int freq[26] = {0};

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        q.push(ch);
        freq[ch - 'a']++;

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }

    cout << endl;
}

int main() {
    string str = "aabccxb";

    FirstNonRepeat(str);

    return 0;
}
