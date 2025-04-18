#include "Tree.h"
#include <iostream>
void Tree::destroyTree(bnode *T)
{
    if(T){
        destroyTree(T->lchild);
        destroyTree(T->rchild);
        delete T;
    }
}
Tree::Tree()
{
    root = new bnode;
    root->lchild = nullptr;
    root->rchild = nullptr;
}
Tree::~Tree() 
{
    destroyTree(root);
}
bnode* Tree::get_root()const
{
    return root;
}
