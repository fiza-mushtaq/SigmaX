#include <iostream>
using namespace std;

int main() {
        int n;
        cout << "enter a number: ";
        cin >> n;
        
        int sum = 0;
        int num = n;

        while(num > 0){
            int digit = num % 10;
            sum += digit * digit * digit;
            num /= 10;
        }

        if( sum == n){
            cout << n << " is an Armstrong number." << endl;
         } else {
            cout << n << " is not an Armstrong number." << endl;
         }

    return 0;
}