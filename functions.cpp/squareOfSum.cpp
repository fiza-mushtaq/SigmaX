#include <iostream>
using namespace std;

void squareOfSum( int a, int b ){
    cout<< a*a + b*b+ 2*a*b;
}

int main() {
    int a = 3;
    int b = 4;
    squareOfSum(a,b);

    return 0;
}