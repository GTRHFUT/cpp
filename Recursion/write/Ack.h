#pragma once
#include <iostream>
#include <stack>
// 已知ACKMANN函数定义如下, 试分别编写出求解该函数的递归过程和非递归函数。
//  Ack(m, n) = n + 1     m = 0
//  Ack(m, n) = Ack(m - 1, 1)    n = 0
//  Ack(m, n) = Ack(m - 1, Ack(m, n - 1))     m > 0, n > 0
int Ack(int m, int n)
{
    if (m == 0)
        return n + 1;
    if (n == 0)
        return Ack(m - 1, 1);
    return Ack(m - 1, Ack(m, n - 1));
}
int ack(int m, int n)
{
    struct task
    {
        int m, n;
        task(int m, int n) : m(m), n(n) {}
    };
    std::stack<task> s;
    s.push({m, n});
    while (!s.empty())
    {
        task current = s.top();
        s.pop();
        if (current.m == 0)
        {
            if (!s.empty())
            {
                task &prev = s.top();
                prev.n = current.n + 1;
            }
            else
            {
                return current.n + 1;
            }
        }
        else if (current.n == 0)
        {
            s.push({current.m - 1, 1});
        }
        else
        {
            s.push({current.m - 1, 0}); // 这个0只是个占位符，填多少都无所谓
            s.push({current.m, current.n - 1});
        }
    }
    std::cerr << "错误：在阿克曼函数计算过程中出现了意外情况。 " << std::endl;
    return 0;
}