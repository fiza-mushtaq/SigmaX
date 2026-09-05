#include <iostream>
using namespace std;

void sumOfDig(int num){
    int n = num; 
    int sum = 0;

    while(n > 0){
        sum += (n % 10);
        n /= 10;
    }
    cout << "Sum of digits is: "<< sum << endl;
}

int main() {
    int n;
    cout<< "Enter a number:";
    cin>> n;
    sumOfDig(n);
    return 0;
}