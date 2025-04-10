#include <iostream>
#include "BinaryTree.h"
BinaryTree::BinaryTree(const int n)
{
    data = new char[n + 1];
    count = 0;
}
BinaryTree::~BinaryTree()
{
    delete[] data;
}
void BinaryTree::createBinaryTree()
{
    std::cout << "Please enter nodes' value (input '#' to end): " << std::endl;
    char value;
    while (true)
    {
        std::cin >> value;
        if (value == '#')
            return;
        if (count >= 13) // 防止数组越界
        {
            std::cout << "Array is full!" << std::endl;
            return;
        }
        data[++count] = value;
    }
}
void BinaryTree::print() const
{
    for (int i = 1; i <= count; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
int BinaryTree::Findfather(const int i){
    return i / 2 > 0 ? i / 2 : -1;
} 
int BinaryTree::FindLeftChild(const int i)
{
    return i * 2 <= 13 ? i * 2 : -1;
}
int BinaryTree::FindRightChild(const int i)
{
    return i * 2 + 1 <= 13 ? i * 2 + 1 : -1;
}
int BinaryTree::FindLeastCommonAncestor(const int i, const int j)
{
    int ii = i, jj = j;
    while (ii != jj)
    {
        if (ii > jj)
            ii /= 2;
        else
            jj /= 2;
    }
    return ii != i && ii != j ? ii : ii / 2;
}
