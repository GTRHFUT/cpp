#pragma once
#include <iostream>
#include <queue>
// 第i行第j个
int number(int i, int j)
{
    if (j == 1 || j == i)
        return 1;
    return number(i - 1, j - 1) + number(i - 1, j);
}
void YangHuiTriangle_1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << number(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

void YangHuiTriangle_2(int n)
{
    std::queue<int>q;
    int s1, s2;
    std::cout << 1 << std::endl;
    q.push(1);
    for(int i = 2; i <= n; i++){
        s1 = 0;
        for(int j = 1; j <= i - 1; j++){
            s2 = q.front();
            q.pop();
            std::cout << s1 + s2 << " ";
            q.push(s1 + s2);
            s1 = s2;
        }
        std::cout << 1 << std::endl;
        q.push(1);
    }
}