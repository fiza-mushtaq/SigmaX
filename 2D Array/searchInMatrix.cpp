#include <iostream>
using namespace std;

bool search(int mat[4][4], int n, int m, int key)
{
    int i = 0, j = m - 1;

    while (i < n && j >= 0)
    {
        if (mat[i][j] == key)
        {
            cout << "found at cell (" << i << "," << j << ")\n";
            return true;
        }
        else if (mat[i][j] > key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    cout << "key not found.\n";
}

int main()
{
    int mat[4][4] = {{2, 3, 4, 5},
                     {7, 6, 8, 9},
                     {4, 3, 5, 6},
                     {7, 3, 4, 0}};
    search(mat, 4, 4, 9);
    return 0;
}