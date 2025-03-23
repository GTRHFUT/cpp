#pragma once
class MyCircularQueue
{
private:
    int* data;
    int front;
    int rear;
    int capacity;
public:
    MyCircularQueue(int k);//构造器，设置队列长度为 k
    ~MyCircularQueue();//析构器
    bool enQueue(int value);//向循环队列插入一个元素。如果成功插入则返回真
    bool deQueue();//从循环队列中删除一个元素。如果成功删除则返回真
    int Front()const;//如果队列为空，返回 -1 
    int Rear()const;//获取队尾元素。如果队列为空，返回 -1
    bool isEmpty()const;//检查循环队列是否为空
    bool isFull()const;//检查循环队列是否已满
};