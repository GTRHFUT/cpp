#include <iostream>
#include <stack>
void P(int W)
{
    if (W > 0)
    {
        std::cout << W;
        P(W - 1);
        std::cout << W;
    }
}
void p(int W)
{
    std::stack<int> s;
    while (W > 0)
    {
        std::cout << W;
        s.push(W);
        W--;
    }
    while (!s.empty())
    {
        W = s.top();
        s.pop();
        std::cout << W;
    }
}