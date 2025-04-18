#pragma once
#include <iostream>
#include <stack>
struct node{
    char data;
    node* lchild;
    node* rchild;
};
void preorder(node* p){
    std::stack<node*>s;
    while(p || !s.empty()){
        while(p){
            std::cout << p->data;
            s.push(p);
            p = p->lchild;
        }
        if(!s.empty()){
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}