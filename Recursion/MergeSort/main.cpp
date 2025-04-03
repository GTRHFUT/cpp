#include <iostream>
#include "MergeSort.h"
using namespace std;
const void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {7, 10, 1, 3, 5, 2, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, n - 1);
    print(arr, n);
    system("pause");
    return 0;
}