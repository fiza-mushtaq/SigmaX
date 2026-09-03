#include <iostream>
using namespace std;

int main() {
    int pencilCost, penCost, eraserCost;
        cout << "Enter cost of pencil: ";
        cin >> pencilCost;         
        cout << "Enter cost of pen: ";      
        cin >> penCost;
        cout << "Enter cost of eraser: ";   
        cin >> eraserCost;

    int totalCost = pencilCost + penCost + eraserCost;
    cout << "Total cost of pencil, pen and eraser is: " << totalCost << endl;

    int costWithTax = totalCost + (totalCost * 0.18);
    cout << "Total cost with 18% tax is: " << costWithTax << endl;

    return 0;
}