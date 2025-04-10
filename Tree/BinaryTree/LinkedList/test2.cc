#include <iostream>
#include "BinaryTree.h"

void test2(){
    BinaryTree bt2;
    bt2.get_root()->data = 'A';
    bt2.get_root()->lchild = new bnode();
    bt2.get_root()->lchild->data = 'B';
    bt2.get_root()->lchild->lchild = new bnode;
    bt2.get_root()->lchild->rchild = new bnode;
    bt2.get_root()->lchild->lchild->data = 'C';
    bt2.get_root()->lchild->rchild->data = 'E';
    bt2.get_root()->lchild->lchild->lchild = nullptr;
    bt2.get_root()->lchild->lchild->rchild = new bnode;
    bt2.get_root()->lchild->lchild->rchild->data = 'D';
    bt2.get_root()->lchild->lchild->rchild->lchild = nullptr;
    bt2.get_root()->lchild->lchild->rchild->rchild = nullptr;
    bt2.get_root()->lchild->rchild->lchild = nullptr;
    bt2.get_root()->lchild->rchild->rchild = new bnode;
    bt2.get_root()->lchild->rchild->rchild->data = 'F';
    bt2.get_root()->lchild->rchild->rchild->lchild = nullptr;
    bt2.get_root()->lchild->rchild->rchild->rchild = nullptr;

    bt2.get_root()->rchild = new bnode;
    bt2.get_root()->rchild->data = 'G';
    bt2.get_root()->rchild->lchild = new bnode;
    bt2.get_root()->rchild->lchild->data = 'H';
    bt2.get_root()->rchild->lchild->lchild = nullptr;
    bt2.get_root()->rchild->lchild->rchild = nullptr;
    bt2.get_root()->rchild->rchild = new bnode;
    bt2.get_root()->rchild->rchild->data = 'I';
    bt2.get_root()->rchild->rchild->lchild = nullptr;
    bt2.get_root()->rchild->rchild->rchild = nullptr;

    std::cout << "深度优先先序遍历：" << std::endl;
    bt2.print_preorder(bt2.get_root());
    std::cout << std::endl;
    std::cout << "深度优先中序遍历：" << std::endl;
    bt2.print_inorder(bt2.get_root());
    std::cout << std::endl;
    std::cout << "深度优先后序遍历：" << std::endl;
    bt2.print_postorder(bt2.get_root());
    std::cout << std::endl;

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "叶子结点的值: " << std::endl;
    bt2.print_AllLeaves(bt2.get_root());
    std::cout << std::endl;

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "结点的值: 序号, 层次: " << std::endl;
    int sequence = 1;
    bt2.print_preorder_data_sequence_layer(bt2.get_root(), sequence, 1);

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "根结点到叶子结点的路径: " << std::endl;
    std::stack<bnode *> s;
    bt2.print_path_root_to_leaves(bt2.get_root(), s);

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "树的高度为: " << bt2.get_height(bt2.get_root()) << std::endl;

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "树的结点数为(方法一): " << bt2.get_node_Numbers(bt2.get_root()) << std::endl;
    int k = 0;
    bt2.get_node_Numbers(bt2.get_root(), k);
    std::cout << "树的结点数为(方法二): " << k << std::endl;

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "叶子的结点数为(方法一): " << bt2.get_leaves_Numbers(bt2.get_root()) << std::endl;
    k = 0;
    bt2.get_leaves_Numbers(bt2.get_root(), k);
    std::cout << "叶子的结点数为(方法二): " << k << std::endl;
 
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "以先序遍历的最后一个结点的值为: ";
    bt2.print_LastNodeValue_Ofpreorder();

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "将二叉链表转换为顺序存储: " << std::endl;
    int n = bt2.get_node_SumSequence(bt2.get_root());
    char *arr = new char[n + 1];
    for(int i = 1; i <=n; i++){
        arr[i] = '^';
    }
    bt2.convert_LinkedList_to_sequence(bt2.get_root(), 1, arr);
    bt2.print_Array(arr, n);

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "输出二叉树先序遍历的前k个结点的值: " << std::endl;
    int num = 0;
    bt2.print_preorder_first_k_nodes(bt2.get_root(), num, 6);
    std::cout << std::endl;

}