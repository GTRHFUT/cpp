#include <iostream>
#include <windows.h>
#include "BinaryTree.h"
#include "preorder_thread_test.cc"
#include "inorder_thread_test.cc"
#include "postorder_thread_test.cc"
int main()
{
    SetConsoleOutputCP(65001);
    BinaryTree bt;
    bnode *T = bt.get_root();
    T->data = 'A';
    T->lchild = new bnode('B');
    T->lchild->lchild = new bnode('C');
    T->lchild->rchild = new bnode('D');
    T->lchild->rchild->lchild = new bnode('E');
    T->lchild->rchild->rchild = new bnode('F');

    T->rchild = new bnode('G');
    T->rchild->lchild = new bnode('H');
    T->rchild->rchild = new bnode('I');

    // preorder_thread_test(bt, T);
    // inorder_thread_test(bt, T);
    postorder_thread_test(bt, T);
    system("pause");
    return 0;
}