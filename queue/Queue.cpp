#include<iostream>
#include"Queue.h"
using namespace std;

// 初始化
Queue::Queue()
{
    count = 0;
    front = new Node;
    front->next = nullptr;
    rear = front;
}
// 析构函数
Queue::~Queue()
{
    while (!empty())
    {
        serve();
    }
    delete front;
    front = nullptr;
}
// 队列是否为空
bool Queue::empty() const
{
    return count == 0;
}
// 入队
void Queue::append(const int x)
{
    Node *newnode = new Node;
    newnode->data = x;
    newnode->next = nullptr;

    rear->next = newnode;
    rear = newnode;
    count++;
}
// 出队
void Queue::serve()
{
    if (!empty())
    {
        Node *temp = front->next;
        front->next = temp->next;
        delete temp;
        count--;
        if (front->next == nullptr)
            rear = front;
        return;
    }
    cout << "The queue is empty!" << endl;
}
// 取队头元素
void Queue::get_front(int &x) const
{
    if (!empty())
    {
        x = front->next->data;
        return;
    }
    cout << "The queue is empty!" << endl;
}
