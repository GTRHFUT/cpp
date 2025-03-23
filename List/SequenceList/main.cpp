#include<iostream>
#include"list.h"
using namespace std;

int main(){
    list l;
    l.createlist();
    l.printlist();
    cout<<"---------------------"<<endl;
    l.insert_element(l.length(),20);
    l.printlist();
    cout<<"---------------------"<<endl;
    l.delete_element(10);
    l.printlist();
    system("pause");
    return 0;
}