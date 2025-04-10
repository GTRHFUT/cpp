#include "BinaryTree.h"
#include <queue>
#include <iostream>
BinaryTree::BinaryTree()
{
    T = new bnode;
    T->lchild = nullptr;
    T->rchild = nullptr;
}
void BinaryTree::destroyTree(bnode *node)
{
    if (node == nullptr)
        return;
    destroyTree(node->lchild);
    destroyTree(node->rchild);
    delete node;
}
BinaryTree::~BinaryTree()
{
    destroyTree(T);
}
bnode *BinaryTree::get_root()
{
    return T;
}
void BinaryTree::createBinaryTree_bf(char arr[], int n)
{
    if (n == 0)
        return;
    std::queue<bnode *> q;
    int i = 0;
    T->data = arr[i++];
    q.push(T);
    while (i < n && !q.empty())
    {
        bnode *front = q.front();
        q.pop();
        // 创建左孩子
        front->lchild = new bnode;
        front->lchild->data = arr[i++];
        front->lchild->lchild = nullptr;
        front->lchild->rchild = nullptr;
        q.push(front->lchild);
        // 创建右孩子
        if (i < n)
        {
            front->rchild = new bnode;
            front->rchild->data = arr[i++];
            front->rchild->lchild = nullptr;
            front->rchild->rchild = nullptr;
            q.push(front->rchild);
        }
    }
}
void BinaryTree::print_bf() const
{
    if (T == nullptr)
        return;
    std::queue<bnode *> q;
    q.push(T);
    while (!q.empty())
    {
        bnode *current = q.front();
        std::cout << current->data << " ";

        if (current->lchild)
            q.push(current->lchild);
        if (current->rchild)
            q.push(current->rchild);
        q.pop();
    }
    std::cout << std::endl;
}
void BinaryTree::print_preorder(bnode *node) const
{
    if (node)
    {
        std::cout << node->data << " ";
        print_preorder(node->lchild);
        print_preorder(node->rchild);
    }
}
void BinaryTree::print_inorder(bnode *node) const
{
    if (node)
    {
        print_inorder(node->lchild);
        std::cout << node->data << " ";
        print_inorder(node->rchild);
    }
}
void BinaryTree::print_postorder(bnode *node) const
{
    if (node)
    {
        print_postorder(node->lchild);
        print_postorder(node->rchild);
        std::cout << node->data << " ";
    }
}
void BinaryTree::print_AllLeaves(bnode *node) const
{
    if (!node)
        return;
    if (!node->lchild && !node->rchild)
    {
        std::cout << node->data << " ";
        return;
    }
    print_AllLeaves(node->lchild);
    print_AllLeaves(node->rchild);
}
void BinaryTree::print_preorder_data_sequence_layer(bnode *node, int &sequence, int layer) const
{
    if (node)
    {
        std::cout << node->data << ": " << sequence++ << "," << layer << std::endl;
        print_preorder_data_sequence_layer(node->lchild, sequence, layer + 1);
        print_preorder_data_sequence_layer(node->rchild, sequence, layer + 1);
    }
}
void BinaryTree::print_path_root_to_leaves(bnode *node, std::stack<bnode *> s) const
{
    if (!node)
        return;
    s.push(node);
    if (!node->lchild && !node->rchild)
    {
        std::stack<char> path;
        while (!s.empty())
        {
            path.push(s.top()->data);
            s.pop();
        }
        std::cout << path.top();
        path.pop();
        while (!path.empty())
        {
            std::cout << "-->" << path.top();
            path.pop();
        }
        std::cout << std::endl;
    }
    else
    {
        print_path_root_to_leaves(node->lchild, s);
        print_path_root_to_leaves(node->rchild, s);
    }
}
int BinaryTree::get_height(bnode *node) const
{
    if (!node)
        return 0;
    return std::max(get_height(node->lchild), get_height(node->rchild)) + 1;
}
int BinaryTree::get_node_Numbers(bnode *node) const
{
    if (!node)
        return 0;
    return get_node_Numbers(node->lchild) + get_node_Numbers(node->rchild) + 1;
}
void BinaryTree::get_node_Numbers(bnode *node, int &k) const
{
    if (node)
    {
        k++;
        get_node_Numbers(node->lchild, k);
        get_node_Numbers(node->rchild, k);
    }
}
int BinaryTree::get_leaves_Numbers(bnode *node) const
{
    if (!node)
        return 0;
    if (!node->lchild && !node->rchild)
        return 1;
    return get_leaves_Numbers(node->lchild) + get_leaves_Numbers(node->rchild);
}
void BinaryTree::get_leaves_Numbers(bnode *node, int &k) const
{
    if (!node)
        return;
    if (!node->lchild && !node->rchild)
    {
        k++;
        return;
    }
    get_leaves_Numbers(node->lchild, k);
    get_leaves_Numbers(node->rchild, k);
}
void BinaryTree::print_LastNodeValue_Ofpreorder() const
{
    bnode *current = T;
    while (current->lchild || current->rchild)
    {
        if (current->rchild)
        {
            current = current->rchild;
        }
        else
        {
            current = current->lchild;
        }
    }
    std::cout << current->data << std::endl;
}
void BinaryTree::convert_LinkedList_to_sequence(bnode *node, int i, char arr[]) const
{
    if (node)
    {
        arr[i] = node->data;
        convert_LinkedList_to_sequence(node->lchild, 2 * i, arr);
        convert_LinkedList_to_sequence(node->rchild, 2 * i + 1, arr);
    }
}
void BinaryTree::print_Array(char arr[], int n) const
{
    for (int i = 1; i <= n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int BinaryTree::get_node_SumSequence(bnode *node) const
{
    std::queue<bnode *> q;
    int sequence = 0;
    q.push(node);
    sequence++;
    while (!q.empty())
    {
        bnode *front = q.front();
        q.pop();
        if (front->lchild || front->rchild)
        {
            if (front->lchild)
                q.push(front->lchild);
            sequence++;
            if (front->rchild)
                q.push(front->rchild);
            sequence++;
        }
    }
    return sequence;
}
void BinaryTree::print_preorder_first_k_nodes(bnode *node, int &num, int k) const
{
    if (node)
    {
        if (num < k)
        {
            std::cout << node->data << " ";
            num++;
            print_preorder_first_k_nodes(node->lchild, num, k);
            print_preorder_first_k_nodes(node->rchild, num, k);

        }
    }
}
