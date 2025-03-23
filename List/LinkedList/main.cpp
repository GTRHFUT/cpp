#include<iostream>
#include"list.h"
using namespace std;
int main(){
    list l;
    l.create_R();
    // l.create_H();
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