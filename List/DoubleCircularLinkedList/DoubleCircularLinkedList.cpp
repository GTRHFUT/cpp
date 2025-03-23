#include <iostream>
#include "DoubleCircularLinkedList.h"
using namespace std;

DoubleCircularLinkedList::DoubleCircularLinkedList()
{
    count = 0;
    head = new Node;
    head->prior = head;
    head->next = head;
}
DoubleCircularLinkedList::~DoubleCircularLinkedList()
{
    Node *current = head->next;
    while (current != head)
    {
        Node *temp = current->next;
        delete current;
        current = temp;
    }
    delete head;
}
int DoubleCircularLinkedList::length() const
{
    return count;
}
void DoubleCircularLinkedList::get_element(const int i, int &x) const
{
    if (i < 1 || i > count)
    {
        cout << "range_error!" << endl;
        return;
    }
    int j = 1;
    Node *current = head->next;
    while (j != i)
    {
        j++;
        current = current->next;
    }
    x = current->data;
}
Node *DoubleCircularLinkedList::locate(const int x) const
{
    Node *current = head->next;
    while (current != head)
    {
        if (current->data == x)
            return current;
        else
            current = current->next;
    }

    return nullptr;
}
void DoubleCircularLinkedList::insert_element(const int i, const int x)
{
    if (i < 1 || i > count + 1)
    {
        cout << "range_error!" << endl;
        return;
    }
    Node *current = head->next;
    int j = 1;
    while (j != i)
    {
        j++;
        current = current->next;
    }
    Node *newnode = new Node;
    newnode->data = x;
    newnode->prior = current->prior;
    newnode->next = current;
    current->prior = newnode;
    newnode->prior->next = newnode;
    count++;
}
void DoubleCircularLinkedList::delete_element(const int i)
{
    if (i < 1 || i > count)
    {
        cout << "range_error!" << endl;
        return;
    }
    Node *current = head->next;
    int j = 1;
    while (j != i)
    {
        j++;
        current = current->next;
    }
    current->prior->next = current->next;
    current->next->prior = current->prior;
    delete current;
    count--;
}
Node *DoubleCircularLinkedList::get_head()
{
    return head;
}
void DoubleCircularLinkedList::create_R()
{
    Node* rear = head;
    int x;
    cout << "Enter the Elements(End: Please enter -1!): " << endl;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            rear->next = head;
            return;
        }
        Node* newnode = new Node;
        newnode->data = x;
        rear->next = newnode;
        newnode->prior = rear;
        rear = newnode;
        count++;
    }
}
void DoubleCircularLinkedList::print() const
{
    Node *current = head->next;
    while (current != head)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
