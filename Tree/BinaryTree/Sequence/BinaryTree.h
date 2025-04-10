#pragma once
class BinaryTree{
private:
    int count;
    char* data;
public:
    BinaryTree(const int n);
    ~BinaryTree();
    void createBinaryTree();
    void print()const;
    int Findfather(const int i);
    int FindLeftChild(const int i);
    int FindRightChild(const int i);
    int FindLeastCommonAncestor(const int i, const int j);
};