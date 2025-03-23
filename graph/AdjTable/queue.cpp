#include <iostream>
#include "queue.h"
using namespace std;

queue::queue()
{
    count = 0;
    front = new Node;
    front->next = nullptr;
    rear = front;
}
queue::~queue()
{
    while (!empty())
    {
        serve();
    }
    delete front;
    front = nullptr;
}
bool queue::empty() const
{
    return count == 0;
}
void queue::append(const int x)
{
    Node *newnode = new Node;
    newnode->data = x;
    newnode->next = nullptr;
    rear->next = newnode;
    rear = newnode;
    count++;
}
void queue::serve()
{
    if (empty())
    {
        cout << "queue is empty!" << endl;
        return;
    }
    Node *temp = front->next;
    front->next = temp->next;
    delete temp;
    if (front->next == nullptr)
    {
        rear = front;
    }
    count--;
}
void queue::get_front(int& x) const
{
    if (empty())
    {
        cout << "queue is empty!" << endl;
        return;
    }
    x = front->next->data;
}
