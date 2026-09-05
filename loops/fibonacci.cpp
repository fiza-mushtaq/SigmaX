#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "enter a number upto which you want the series to be: ";
    cin >> n;

    int first = 0, second = 1;
    cout << first << " " << second <<" ";

    for(int i=2; i < n; i++){
        int third = first + second;
        cout << third << " ";
        first = second;
        second = third;
    }
         
return 0;
}