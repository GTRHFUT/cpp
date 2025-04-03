// B[1]开始为第一个元素,n为w[]的元素个数 - 1
#pragma once
#include <iostream>
const void Print_bag(int w[], int B[], int num)
{
    for (int i = 1; i <= num; i++)
    {
        std::cout << "(" << B[i] + 1 << "," << w[B[i]] << ")  ";
    }
    std::cout << std::endl;
}
void Bag(int w[], int n, int S, int B[], int S1, int num, int k)
{
    if (k <= n)
    {
        if (S1 + w[k] == S)
        {
            B[num + 1] = k;
            Print_bag(w, B, num + 1); // 输出求解结果
        }
        if (S1 + w[k] < S)
        {
            B[num + 1] = k;
            Bag(w, n, S, B, S1 + w[k], num + 1, k + 1);
        } // 放入第k个物品再试探
        Bag(w, n, S, B, S1, num, k + 1); // 不放第k个物品的试探
    }
}