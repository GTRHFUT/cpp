#include "BinaryTree.h"
void BinaryTree::destroyTree(bnode *node)
{
    if (node && node->ltag == 0 && node->rtag == 0)
    {
        destroyTree(node->lchild);
        destroyTree(node->rchild);
        delete node;
        node = nullptr;
    }
}
BinaryTree::BinaryTree()
{
    T = new bnode;
}
BinaryTree::~BinaryTree()
{
    destroyTree(T);
}
bnode *BinaryTree::get_root()
{
    return T;
}
void BinaryTree::preorder_thread(bnode *T, bnode *&pre)
{
    if (T)
    {
        if (!T->lchild)
        {
            T->lchild = pre;
            T->ltag = 1;
        }
        if (pre && pre->rtag == 1)
        {
            pre->rchild = T;
        }
        if (!T->rchild)
            T->rtag = 1;
        pre = T;
        if (T->ltag == 0)
            preorder_thread(T->lchild, pre);
        if (T->rtag == 0)
            preorder_thread(T->rchild, pre);
    }
}
void BinaryTree::inorder_thread(bnode *T, bnode *&pre)
{
    if (T)
    {
        if (T->ltag == 0)
            inorder_thread(T->lchild, pre);
        if (!T->lchild)
        {
            T->lchild = pre;
            T->ltag = 1;
        }
        if (pre && pre->rtag == 1)
        {
            pre->rchild = T;
        }
        if (!T->rchild)
            T->rtag = 1;
        pre = T;
        if (T->rtag == 0)
            inorder_thread(T->rchild, pre);
    }
}
void BinaryTree::postorder_thread(bnode *T, bnode *&pre)
{
    if (T)
    {
        if (T->ltag == 0)
            postorder_thread(T->lchild, pre);
        if (T->rtag == 0)
            postorder_thread(T->rchild, pre);
        if (!T->lchild)
        {
            T->lchild = pre;
            T->ltag = 1;
        }
        if (pre && pre->rtag == 1)
        {
            pre->rchild = T;
        }
        if (!T->rchild)
            T->rtag = 1;
        pre = T;
    }
}

bnode *BinaryTree::preorder_next(bnode *node) const
{
    if (!node)
        return nullptr;
    if (node->ltag == 0)
        return node->lchild;
    else
        return node->rchild;
}
/* bnode* BinaryTree::preorder_front(bnode* node)const
{
    1.如果为根节点，无前驱
    2.如果为左孩子结点，则前驱为父节点
    3.如果为右孩子结点，则为左兄弟子树中最右下的叶子结点
}
 */
bnode *BinaryTree::inorder_next(bnode *node) const
{
    if (!node)
        return nullptr;
    bnode *q = node->rchild;
    if (node->rtag == 1)
        return q;
    while (q->ltag == 0)
    {
        q = q->lchild;
    }
    return q;
}
bnode* BinaryTree::inorder_front(bnode* node)const
{
    if(!node)return nullptr;
    bnode* q = node->lchild;
    if(node->ltag == 0){
        while(q->rtag == 0){
            q = q->rchild;
        }
        return q;
    }
    //如果没有左孩子，则是其前驱线索
    return q;
}
bnode* BinaryTree::postorder_front(bnode* node)const
{
    if(!node)return nullptr;
    if(node->rtag == 0)return node->rchild;
    //如果没有，则为其左孩子或其前驱线索
    return node->lchild;
}
/* bnode* BinaryTree::postorder_next(bnode* node)const
{
    1.根节点无后继
    2.若为右孩子，其父节点
    3.若为左孩子:
        A:无右兄弟，则为其父节点
        B:有右兄弟，右兄弟子树最左下的叶子结点
}
 */