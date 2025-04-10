#pragma once 
struct bnode{
    char data;
    int ltag, rtag;
    bnode* lchild, *rchild;
    bnode(char val):data(val),ltag(0),rtag(0),lchild(nullptr),rchild(nullptr){}
    bnode():ltag(0),rtag(0),lchild(nullptr),rchild(nullptr){}
};

class BinaryTree{
private:
    bnode* T;
    void destroyTree(bnode *node);
public:
    // 初始化二叉树
    BinaryTree();
    // 析构
    ~BinaryTree();
    // 获取二叉树的根节点
    bnode *get_root();
    // 先序线索化
    void preorder_thread(bnode* T, bnode*& pre);
    // 中序线索化
    void inorder_thread(bnode* T, bnode*& pre);
    // 后序线索化
    void postorder_thread(bnode* T, bnode*& pre);
    // 求结点的先序后继
    bnode* preorder_next(bnode* node)const;
    // 求结点的先序前驱
    bnode* preorder_front(bnode* node)const;
    // 求结点的中序后继
    bnode* inorder_next(bnode* node)const;
    // 求结点的中序前驱
    bnode* inorder_front(bnode* node)const;
    // 求结点的后序前驱
    bnode* postorder_front(bnode* node)const;
    // 求结点的后序后驱
    bnode* postorder_next(bnode* node)const;
};