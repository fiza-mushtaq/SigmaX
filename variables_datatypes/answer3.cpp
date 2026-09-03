#include <iostream>
using namespace std;

int main() {
        
    //simple interest calculator
    int principal = 10000;
    int rate = 5;
    int time =2;
    int simpleInterest = (principal * rate * time) / 100;
    cout << "The simple interest is: " << simpleInterest << endl;
    cout << "Total amount to repay is: " << (principal + simpleInterest) << endl;


    return 0;
}