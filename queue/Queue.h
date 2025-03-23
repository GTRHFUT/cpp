#pragma once

struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    int count;
    Node *front, *rear;
public:
    //初始化
    Queue();
    //析构函数
    ~Queue();
    //队列是否为空
    bool empty()const;
    //入队
    void append(const int x);
    //出队
    void serve();
    //取队头元素
    void get_front(int& x)const;
};