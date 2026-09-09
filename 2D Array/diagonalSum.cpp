#include <iostream>
using namespace std;

void diagonalSum(int mat[][4], int n, int m)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];

        if (i != n - i - 1)
        {
            sum += mat[i][n - i - 1];
        }
    }
    cout << sum << endl;
}

int main()
{
    int mat[4][4] = {{2, 3, 4, 5},
                     {7, 6, 8, 9},
                     {4, 3, 5, 6},
                     {7, 3, 4, 0}};

    diagonalSum(mat, 4, 4);
    return 0;
}