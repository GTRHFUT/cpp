#include <iostream>
#include <windows.h>
#include "Tree.h"
#include "Forest.h"
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    
    // 创建三棵树
    Tree trees[3];
    
    // 构建第一棵树
    bnode* root1 = trees[0].get_root();
    root1->data = 'A';
    root1->lchild = new bnode('B');
    root1->lchild->lchild = new bnode('D');
    root1->lchild->rchild = new bnode('E');
    root1->rchild = new bnode('C');
    
    // 构建第二棵树
    bnode* root2 = trees[1].get_root();
    root2->data = 'F';
    root2->lchild = new bnode('G');
    root2->lchild->lchild = new bnode('I');
    root2->rchild = new bnode('H');
    
    // 构建第三棵树
    bnode* root3 = trees[2].get_root();
    root3->data = 'J';
    root3->lchild = new bnode('K');
    
    // 创建森林并转换
    Forest forest;
    forest.convert_tree_to_forest(trees, 3);
    
    cout << "-------森林先序遍历-------" << endl;
    forest.preorder(forest.get_root());
    cout << endl;
    
    cout << "-------森林后序遍历-------" << endl;
    forest.postorder(forest.get_root());
    cout << endl;
    
    cout << "-------森林叶子节点数-------" << endl;
    cout << forest.leaf(forest.get_root()) << endl;
    
    cout << "-------森林的高度-------" << endl;
    cout << forest.height(forest.get_root()) << endl;
    
    cout << "-------森林的父子对-------" << endl;
    forest.parent_children(forest.get_root());
    cout << endl;
    system("pause");
    return 0;
}