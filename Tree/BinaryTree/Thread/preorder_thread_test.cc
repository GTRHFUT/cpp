#include "BinaryTree.h"
#include <iostream>
void preorder_thread_test(BinaryTree &bt, bnode *T)
{
    bnode *temp = nullptr;
    bt.preorder_thread(T, temp);
    std::cout << "----------先序后继----------" << std::endl;
    bnode *next_1 = bt.preorder_next(T->lchild);
    std::cout << T->lchild->data << " 的先序后继是: " << next_1->data << std::endl;

    bnode *next_2 = bt.preorder_next(T->lchild->lchild);
    std::cout << T->lchild->lchild->data << " 的先序后继是: " << next_2->data << std::endl;

    bnode *next_3 = bt.preorder_next(T);
    std::cout << T->data << " 的先序后继是: " << next_3->data << std::endl;

    bnode *next_4 = bt.preorder_next(T->lchild->rchild->rchild);
    std::cout << T->lchild->rchild->rchild->data << " 的先序后继是: " << next_4->data << std::endl;

    bnode *next_5 = bt.preorder_next(T->rchild->rchild);
    if (next_5)
    {
        std::cout << T->rchild->rchild->data << " 的先序后继是: " << next_5->data << std::endl;
    }
    else
    {
        std::cout << T->rchild->rchild->data << " 的先序后继是: " << "None!" << std::endl;
    }
}