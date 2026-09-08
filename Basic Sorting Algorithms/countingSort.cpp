#include <iostream>
#include <climits>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void countingSort(int *arr, int n)
{
    int freq[10000] = {0};

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;

        if (arr[i] < minVal)
            minVal = arr[i];

        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    for (int i = maxVal; i >= minVal; i++)    //traversing the frequency array
    {
        while (freq[i] > 0)
        {
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
    printArr(arr, n);
}

int main()
{
    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int n = sizeof(arr) / sizeof(int);

    countingSort(arr, n);

    return 0;
}