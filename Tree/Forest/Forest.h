#pragma once
#include "Tree.h"
struct fnode{
    char data;
    fnode* firstchild, *nextbrother;
    fnode(int data):data(data),firstchild(nullptr),nextbrother(nullptr){}
    fnode(){}
};
class Forest{
private:
    fnode* root;
    fnode* convert_subtree(bnode* tree_node);
public:
    Forest();
    void convert_tree_to_forest(Tree[], int n);
    fnode* get_root()const;
    void preorder(fnode *T) const;
    void postorder(fnode* T)const;
    int leaf(fnode* T)const;
    int height(fnode* T)const;
    //求树/森林中所有的父子对
    void parent_children(fnode* T)const;
};