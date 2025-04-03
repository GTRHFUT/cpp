#pragma once
#include <iostream>
// 递归求第n行第i个元素的值
int CalcValue(int i, int n)
{
    if (i == 1 || i == n)
        return 1;
    return CalcValue(i - 1, n - 1) + CalcValue(i, n - 1);
}
void printYangHuiTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << CalcValue(j, i) << "  ";
        }
        std::cout << std::endl;
    }
}