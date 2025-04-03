#pragma once
#include <iostream>
void hanio(int n, char origin, char temp, char destination)
{
    if (n == 1)
    {
        std::cout << "Move disk " << n << " from " << origin << " to " << destination << std::endl;
        return;
    }
    hanio(n - 1, origin, destination, temp);
    std::cout << "Move disk " << n << " from " << origin << " to " << destination << std::endl;
    hanio(n - 1, temp, origin, destination);
}