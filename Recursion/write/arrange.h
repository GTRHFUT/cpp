// 设计算法求从集合｛1, 2, ..., n｝中取k个元素的所有排列
#pragma once
#include <iostream>

const void print_arrange(int arr[], int k)
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

void arrange(int arr[], int num, int k, int n, bool used[])
{
    if (num == 0)
    {
        print_arrange(arr, k);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            arr[k - num] = i;
            arrange(arr, num - 1, k, n, used);
            used[i] = false;
        }
    }
}