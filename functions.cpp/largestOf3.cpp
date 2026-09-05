#include <iostream>
using namespace std;

void largest(int a ,int b ,int c){

    if(a>b && a>c){
        cout << a << " is largest.";
    }else if (b>c){
        cout<< b <<" is largest.";
    }
    else{
        cout << c <<" is largest.";
    }
}
int main() {
    int a = 3;
    int b = 22;
    int c = 78;
    largest(a,b,c);

    return 0;
}