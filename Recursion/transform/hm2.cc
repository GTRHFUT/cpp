#include <iostream>
void PrintRV(int N)
{
    if (N > 0)
    {
        std::cout << N % 10;
        PrintRV(N / 10);
    }
}
void printRV(int N)
{
    while (N > 0)
    {
        std::cout << N % 10;
        N /= 10;
    }
}