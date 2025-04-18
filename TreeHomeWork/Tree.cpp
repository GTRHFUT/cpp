#include <iostream>
#include <queue>
#include "Tree.h"
BTiTree::BTiTree()
{
    root = new bnode;
}
void BTiTree::destroyTree(bnode *p)
{
    if (p)
    {
        destroyTree(p->lchild);
        destroyTree(p->rchild);
        delete p;
        p = nullptr;
    }
}
BTiTree::~BTiTree()
{
    destroyTree(root);
}
bnode *BTiTree::get_root() const
{
    return root;
}
void BTiTree::createBTiTree(int arr[], int n)
{
    if (n <= 0)
        return;
    std::queue<bnode *> q;
    int i = 0;
    root->data = arr[i++];
    q.push(root);
    while (i < n || !q.empty())
    {
        bnode *front;
        if (!q.empty())
        {
            front = q.front();
            q.pop();
        }
        if (i < n && arr[i] != null)
        {
            front->lchild = new bnode(arr[i]);
            q.push(front->lchild);
        }
        i++;
        if (i < n && arr[i] != null)
        {
            front->rchild = new bnode(arr[i]);
            q.push(front->rchild);
        }
        i++;
    }
}
void BTiTree::preorder(bnode *p) const
{
    if (p)
    {
        std::cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void BTiTree::inorder(bnode *p) const
{
    if (p)
    {
        inorder(p->lchild);
        std::cout << p->data << " ";
        inorder(p->rchild);
    }
}
void BTiTree::postorder(bnode *p) const
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        std::cout << p->data << " ";
    }
}
