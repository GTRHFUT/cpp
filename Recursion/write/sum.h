//求数组和
#pragma once
int sum(int arr[], int n)
{
    if (n == 1)
        return arr[n - 1];
    return arr[n - 1] + sum(arr, n - 1);
}