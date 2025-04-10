#include<iostream>
#include"BinaryTree.h"
using namespace std;

int main(){
    BinaryTree bt1(13);
    bt1.createBinaryTree();
    bt1.print();
    cout << bt1.Findfather(13) <<endl;
    cout << bt1.Findfather(1) <<endl;
    cout << bt1.FindLeftChild(5) << endl;
    cout << bt1.FindRightChild(5) << endl;
    cout << bt1.FindLeftChild(7) << endl;
    cout << bt1.FindLeftChild(7) << endl;
    cout << bt1.FindLeastCommonAncestor(13,12) << endl;
    cout << bt1.FindLeastCommonAncestor(3,6) << endl;
    system("pause");
    return 0;
}