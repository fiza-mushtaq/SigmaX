#include <iostream>
using namespace std;

int main() {
        int num;
        cout << "Enter a 3-digit number: ";
        cin >> num;

        int n = num;

        int digit1 = n % 10; // Extract the last digit-
        n /= 10; // Remove the last digit

        int digit2 = n % 10; // Extract the second digit
        n /= 10; // Remove the second digit

        int digit3 = n % 10; // Extract the first digit
        n /= 10; // Remove the first digit
        
        int cubeSum = (digit1 * digit1 * digit1) + (digit2 * digit2 * digit2) + (digit3 * digit3 * digit3);

        if(cubeSum == num) {
            cout << num << " is an Armstrong number." << endl;
        } else {
            cout << num << " is not an Armstrong number." << endl;
        }

    return 0;
}