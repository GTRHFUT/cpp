#pragma once
#include <stack>
struct bnode
{
    char data;
    bnode *lchild, *rchild;
};
class BinaryTree
{
private:
    bnode *T;
    // 释放内存，在析构函数中使用
    void destroyTree(bnode *node);

public:
    // 初始化二叉树
    BinaryTree();
    // 析构
    ~BinaryTree();
    // 获取二叉树的根节点
    bnode *get_root();
    // 按每一层创建二叉树
    void createBinaryTree_bf(char arr[], int n);
    // 按每层输出二叉树各结点的值
    void print_bf() const;
    // 先序输出二叉树各结点的值
    void print_preorder(bnode *node) const;
    // 中序输出二叉树各结点的值
    void print_inorder(bnode *node) const;
    // 后序输出二叉树各结点的值
    void print_postorder(bnode *node) const;
    // 输出所有叶子结点的值
    void print_AllLeaves(bnode *node) const;
    // 先序输出每个结点的值，输出的序号，所在层数
    void print_preorder_data_sequence_layer(bnode *node, int &sequence, int layer) const;
    // 输出根结点到叶子结点的路径
    void print_path_root_to_leaves(bnode *node, std::stack<bnode *> s) const;
    // 获取树的高度（深度）
    int get_height(bnode *node) const;
    // 获取树的结点总个数（方法一）
    int get_node_Numbers(bnode *node) const;
    // 获取树的结点总个数（方法二）
    void get_node_Numbers(bnode *node, int &k) const;
    // 获取叶子结点总个数（方法一）
    int get_leaves_Numbers(bnode *node) const;
    // 获取叶子结点总个数（方法二）
    void get_leaves_Numbers(bnode *node, int &k) const;
    // 非递归算法以输出二叉树中先序序列中最后一个结点的值。
    void print_LastNodeValue_Ofpreorder()const;
    // 将二叉链表存储的二叉树转换为顺序存储形式
    void convert_LinkedList_to_sequence(bnode* node, int i, char arr[])const;
    // 打印数组
    void print_Array(char arr[], int n)const;
    // 获取树的总序号
    int get_node_SumSequence(bnode* node)const;
    // 输出二叉树先序遍历的前k个结点的值
    void print_preorder_first_k_nodes(bnode* node, int& num, int k)const;
};