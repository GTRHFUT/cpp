#include "BinaryTree.h"
#include <iostream>
void postorder_thread_test(BinaryTree &bt, bnode *T)
{
    bnode *temp = nullptr;
    bt.postorder_thread(T, temp);
    std::cout << "----------后序前驱----------" << std::endl;
    bnode *front_1 = bt.postorder_front(T->lchild->lchild);
    if (front_1)
    {
        std::cout << T->lchild->lchild->data << " 的后序前驱是: " << front_1->data << std::endl;
    }
    else
    {
        std::cout << T->lchild->lchild->data << " 的后序前驱是: " << "None!" << std::endl;
    }
    bnode *front_2 = bt.postorder_front(T);

    std::cout << T->data << " 的后序前驱是: " << front_2->data << std::endl;

    bnode *front_3 = bt.postorder_front(T->rchild->rchild);
    std::cout << T->rchild->rchild->data << " 的后序前驱是: " << front_3->data << std::endl;
}
