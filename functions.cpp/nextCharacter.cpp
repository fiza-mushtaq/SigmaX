#include <iostream>
using namespace std;

void next(char ch){
    cout << "The next character is: "<< char(ch + 1);
}

int main() {

    char ch;
    cout<< "Enter a character: ";
    cin>> ch;
    next(ch);

    return 0;
}