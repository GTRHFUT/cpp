//孩子--兄弟链表表示法
#pragma once
struct bnode{
    char data;
    bnode* lchild, *rchild;
    bnode(int data):data(data),lchild(nullptr),rchild(nullptr){}
    bnode(){}
};
class Tree{
private:
    bnode* root;
    void destroyTree(bnode* T);
public:
    Tree();
    ~Tree();
    bnode* get_root()const;
};
