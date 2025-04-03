// 设计算法求集合｛1, 2, ..., n｝的幂集
#pragma once
#include <iostream>
const void print_PowerSet(int arr[], int size)
{
    std::cout << "{";
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            std::cout << arr[i];
            break;
        }
        std::cout << arr[i] << ",";
    }
    std::cout << "} ";
}
void PowerSet(int arr[], int size, int max, int n)
{
    print_PowerSet(arr, size);
    for (int i = max + 1; i <= n; i++)
    {
        arr[size] = i;
        PowerSet(arr, size + 1, i, n);
    }
}