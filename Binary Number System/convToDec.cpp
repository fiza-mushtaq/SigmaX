#include <iostream>
using namespace std;

void convToDec(int num){

    int n = num;
    int decNum = 0;
    int power = 1;      //2^0

    while(n > 0){
        int lastDigit = n % 10;
        decNum += lastDigit * power;
        power *= 2;          //2^1,2^1,......
        n /= 10;
    }

    cout << decNum << endl;

}

int main() {
    convToDec(111111);    
    convToDec(10110);
    convToDec(10011);
    convToDec(110010);

    return 0;
}