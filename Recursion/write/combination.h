//设计算法求从集合｛1, 2, ..., n｝中取k个元素的所有组合
#pragma once
#include <iostream>
const void print_combination(int arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (i == 0)
        {
            std::cout << "{";
        }
        if (i == k - 1)
        {
            std::cout << arr[i] << "} ";
            return;
        }
        std::cout << arr[i] << ",";
    }
}

// 存放组合的数组，元素序号，还要挑选的元素个数，要挑选的总个数，元素总数
void combination(int arr[], int i, int num, int k, int n)
{
    if (num == 0)
    {
        print_combination(arr, k);
    }
    else if (i + num - 1 <= n)
    {
        arr[k - num] = i; //A[i-1]
        combination(arr, i + 1, num - 1, k, n);
        combination(arr, i + 1, num, k, n);
    }
}