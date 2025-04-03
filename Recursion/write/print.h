// 逐行打印输出
#include <iostream>
#pragma once
void print(int n)
{
    if (n == 0) return;
    print(n - 1);
    for (int i = 0; i < n; i++)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}