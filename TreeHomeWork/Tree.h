#pragma once
#define null 0
struct bnode
{
    int data;
    bnode *lchild, *rchild;
    bnode() : lchild(nullptr), rchild(nullptr) {}
    bnode(int data) : data(data), lchild(nullptr), rchild(nullptr) {}
};
class BTiTree
{
private:
    bnode *root;
    void destroyTree(bnode *p);

public:
    BTiTree();
    ~BTiTree();
    bnode* get_root()const;
    void createBTiTree(int arr[], int n);
    void preorder(bnode *p) const;
    void inorder(bnode *p) const;
    void postorder(bnode *p) const;
};