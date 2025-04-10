#include <iostream>
#include <stack>
void PrintV(int N)
{
    if (N > 0)
    {
        PrintV(N / 10);
        std::cout << N % 10;
    }
}

void printV(int N)
{
    std::cout << N;
}
void pprintV(int N)
{
    std::stack<int> s;
    while (N > 0)
    {
        s.push(N);
        N /= 10;
    }
    while (!s.empty())
    {
        N = s.top();
        s.pop();
        std::cout << N % 10;
    }
}