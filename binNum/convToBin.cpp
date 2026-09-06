#include <iostream>
using namespace std;

    void convToBin(int num){

        int n = num;
        int binNum = 0;
        int power = 1;        //10^0  

        while (n>0){

            int remainder = n % 2;
            binNum += remainder * power;        
            power *= 10;                 //10^1,10^2,.....
            n /= 2;

        }
        cout<< binNum << endl;
    }
int main() {

    convToBin(25);
    convToBin(49);
    convToBin(31);
    convToBin(88);

    return 0;
}