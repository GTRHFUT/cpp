#include "Forest.h"
#include <iostream>
Forest::Forest()
{
    root = nullptr;
}
void Forest::convert_tree_to_forest(Tree trees[], int n)
{
    if (n <= 0)
    {
        root = nullptr;
        return;
    }

    // 设置第一棵树为森林的根
    bnode *firstTreeRoot = trees[0].get_root();
    root = new fnode;
    root->data = firstTreeRoot->data;
    root->firstchild = nullptr;
    root->nextbrother = nullptr;

    // 将第一棵树转换为森林节点
    if (firstTreeRoot->lchild)
    {
        root->firstchild = convert_subtree(firstTreeRoot->lchild);
    }
    if (firstTreeRoot->rchild)
    {
        root->firstchild->nextbrother = convert_subtree(firstTreeRoot->rchild);
    }

    fnode *current = root;

    // 处理剩余的树，每棵树都作为前一棵树的兄弟
    for (int i = 1; i < n; i++)
    {
        bnode *treeRoot = trees[i].get_root();
        fnode *newNode = new fnode;
        newNode->data = treeRoot->data;
        newNode->firstchild = nullptr;
        newNode->nextbrother = nullptr;

        // 转换当前树的子树
        if (treeRoot->lchild)
        {
            newNode->firstchild = convert_subtree(treeRoot->lchild);
        }
        if (treeRoot->rchild)
        {
            newNode->firstchild->nextbrother = convert_subtree(treeRoot->rchild);
        }

        // 将新树连接到森林中
        current->nextbrother = newNode;
        current = newNode;
    }
}

// 修改后的转换子树函数
fnode *Forest::convert_subtree(bnode *tree_node)
{
    if (!tree_node)
        return nullptr;

    fnode *forest_node = new fnode;
    forest_node->data = tree_node->data;
    forest_node->firstchild = nullptr;
    forest_node->nextbrother = nullptr;

    // 转换左右子树
    if (tree_node->lchild)
    {
        forest_node->firstchild = convert_subtree(tree_node->lchild);
    }
    if (tree_node->rchild)
    {
        if (forest_node->firstchild)
        {
            forest_node->firstchild->nextbrother = convert_subtree(tree_node->rchild);
        }
    }

    return forest_node;
}
fnode *Forest::get_root() const
{
    return root;
}
void Forest::preorder(fnode *T) const
{
    if (T)
    {
        std::cout << T->data << " ";
        preorder(T->firstchild);
        preorder(T->nextbrother);
    }
}
void Forest::postorder(fnode *T) const
{
    if (T)
    {
        postorder(T->firstchild);
        std::cout << T->data << " ";
        postorder(T->nextbrother);
    }
}
int Forest::leaf(fnode *T) const
{
    if (!T)
        return 0;
    if (!T->firstchild)
        return 1 + leaf(T->nextbrother);
    return leaf(T->firstchild) + leaf(T->nextbrother);
}
int Forest::height(fnode *T) const
{
    if (!T)
        return 0;
    return std::max(height(T->firstchild) + 1, height(T->nextbrother));
}
void Forest::parent_children(fnode *T) const
{
    if (T)
    {
        fnode *current = T->firstchild;
        while (current)
        {
            std::cout << '(' << T->data << ',' << current->data << ")  ";
            current = current->nextbrother;
        }
        parent_children(T->firstchild);
        parent_children(T->nextbrother);
    }
}
