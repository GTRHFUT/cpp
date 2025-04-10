#include <iostream>
#include "BinaryTree.h"
void test1()
{
    BinaryTree bt1;
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};
    bt1.createBinaryTree_bf(data, sizeof(data) / sizeof(data[0]));
    std::cout << "广度优先遍历：" << std::endl;
    bt1.print_bf();
    std::cout << "-----------------------------------------------------" << std::endl;
}
