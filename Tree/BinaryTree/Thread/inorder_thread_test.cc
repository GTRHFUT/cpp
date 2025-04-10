#include "BinaryTree.h"
#include <iostream>
void inorder_thread_test(BinaryTree &bt, bnode *T)
{
    bnode *temp = nullptr;
    bt.inorder_thread(T, temp);
    std::cout << "----------中序后继----------" << std::endl;
    bnode *next_1 = bt.inorder_next(T->lchild);
    std::cout << T->lchild->data << " 的中序后继是: "<< next_1->data << std::endl;

    bnode *next_2 = bt.inorder_next(T->lchild->lchild);
    std::cout << T->lchild->lchild->data << " 的中序后继是: "<< next_2->data << std::endl;

    bnode *next_3 = bt.inorder_next(T);
    std::cout << T->data << " 的中序后继是: "<< next_3->data << std::endl;

    bnode *next_4 = bt.inorder_next(T->lchild->rchild->rchild);
    std::cout << T->lchild->rchild->rchild->data << " 的中序后继是: "<< next_4->data << std::endl;

    bnode *next_5 = bt.inorder_next(T->rchild->rchild);
    if (!next_5)
    {
        std::cout << T->rchild->rchild->data << " 的中序后继是: "<< "None!" << std::endl;
    }
    else
    {
        std::cout << T->rchild->rchild->data << " 的中序后继是: "<< next_5->data << std::endl;
    }


    std::cout << "----------中序前驱----------" << std::endl;    
    bnode* front_1 = bt.inorder_front(T);
    std::cout << T->data << " 的中序前驱是: "<< front_1->data << std::endl;

    bnode* front_2 = bt.inorder_front(T->lchild->lchild);
    if (!front_2)
    {
        std::cout << T->lchild->lchild->data << " 的中序前驱是: "<< "None!" << std::endl;
    }
    else
    {
        std::cout << T->lchild->lchild->data << " 的中序前驱是: "<< front_2->data << std::endl;
    }

    bnode* front_3 = bt.inorder_front(T->rchild->rchild);
    std::cout << T->rchild->rchild->data << " 的中序前驱是: "<< front_3->data << std::endl;
}