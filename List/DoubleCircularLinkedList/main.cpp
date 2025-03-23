#include <iostream>
#include "DoubleCircularLinkedList.h"
using namespace std;

int main(){

    DoubleCircularLinkedList l;
    l.create_R();
    l.print();
    cout<<"---------------------"<<endl;
    l.insert_element(l.length(),20);
    l.print();
    cout<<"---------------------"<<endl;
    l.delete_element(1);
    l.print();
    system("pause");
    return 0;
}