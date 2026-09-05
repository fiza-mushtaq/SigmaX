#include <iostream>
using namespace std;

void palindrome(int num){
    int original = num;
    int rev = 0;

    while(num > 0){
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }

    if(rev == original){
        cout<< "Number is a palindrome.";
    }else{
        cout<<"Number is not a palindrome.";
    }
}

int main() {
    int n;
    cout << "Enter a number:";
    cin >> n;
    palindrome(n);
    return 0;
}