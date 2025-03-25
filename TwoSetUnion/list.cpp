#include <iostream>
#include "list.h"
using namespace std;

List::List()
{
    head = new Node;
    head->next = nullptr;
}
List::~List()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current->next;
        delete current;
        current = temp;
    }
    head = nullptr;
}
Node *List::get_head() const
{
    return head;
}
void List::create_R()
{
    // 如果链表非空的话，先清空链表
    Node *current = head->next;
    while (current != nullptr)
    {
        Node *temp = current->next;
        delete current;
        current = temp;
    }
    
    Node *rear = head;
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            return;
        }
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
    }
}
void List::print() const
{
    Node *current = head->next;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
