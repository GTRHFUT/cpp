#include <windows.h>
#include "test1.cc"
#include "test2.cc"
int main()
{
    SetConsoleOutputCP(65001);
    test1();
    test2();
    system("pause");
    return 0;
}