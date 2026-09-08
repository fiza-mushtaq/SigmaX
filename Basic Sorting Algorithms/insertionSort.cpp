#include <iostream>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int prev = i - 1;

        while (prev >= 0 && key > arr[prev])
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = key;
    }

    printArr(arr, n);
}

int main()
{
    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);

    return 0;
}