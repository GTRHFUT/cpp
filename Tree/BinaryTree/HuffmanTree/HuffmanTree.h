#pragma once
#include <string>
#include <iostream>
#include <algorithm>
struct bnode
{
    int data;
    std::string code;
    bnode *lchild, *rchild;
    bnode(){}
    bnode(int data) : data(data), code(""), lchild(nullptr), rchild(nullptr) {}
};
class HuffmanTree
{
private:
    bnode *root;
public:
    HuffmanTree(int data);
    void destroyTree(bnode* node);
    bnode *get_root() const;
    void createHuffmanTree(HuffmanTree *trees, int n);
    void CodeHuffmanTree(bnode *node, std::string code);
    void printLeaf(bnode* node)const;
    void printCode() const;
};
