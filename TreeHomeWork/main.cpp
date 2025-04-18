#include <iostream>
#include "Tree.h"
using namespace std;
void test1();
void test2();
void test3();
int main()
{
    test1();
    test2();
    test3();
    system("pause");
    return 0;
}
void test1(){
    cout << "----------TEST_1----------" << endl;
    int arr_1[] = {3, 9, 20, null, null, 15, 7};
    int n = sizeof(arr_1)/sizeof(arr_1[0]);
    BTiTree tree;
    tree.createBTiTree(arr_1, n);
    tree.preorder(tree.get_root());
    cout << endl;
    tree.inorder(tree.get_root());
    cout << endl;
    tree.postorder(tree.get_root());
    cout << endl;
}
void test2(){
    cout << "----------TEST_2----------" << endl;
    int arr_2[] = {1};
    int n = sizeof(arr_2)/sizeof(arr_2[0]);
    BTiTree tree;
    tree.createBTiTree(arr_2, n);
    tree.preorder(tree.get_root());
    cout << endl;
    tree.inorder(tree.get_root());
    cout << endl;
    tree.postorder(tree.get_root());
    cout << endl;
}
void test3(){
    cout << "----------TEST_3----------" << endl;
    int arr_3[] = {9, null, null, null};
    int n = sizeof(arr_3)/sizeof(arr_3[0]);
    BTiTree tree;
    tree.createBTiTree(arr_3, n);
    tree.preorder(tree.get_root());
    cout << endl;
    tree.inorder(tree.get_root());
    cout << endl;
    tree.postorder(tree.get_root());
    cout << endl;
}