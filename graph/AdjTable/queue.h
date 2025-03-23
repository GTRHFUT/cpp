#pragma once
#include"node.h"
class queue{
private:
    int count;
    Node* front, *rear;
public:
    queue();
    ~queue();
    bool empty()const;
    void append(const int x);
    void serve();
    void get_front(int& x)const;
};