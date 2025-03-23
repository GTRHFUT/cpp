#include <iostream>
#include "SingleCircularLinkedList.h"
using namespace std;

SingleCircularLinkedList::SingleCircularLinkedList()
{
    count = 0;
    head = new Node;
    head->next = head;
    rear = head;
}
SingleCircularLinkedList::~SingleCircularLinkedList()
{
    Node *current = head->next;
    while (current != head)
    {
        Node* temp = current->next;
        delete current;
        current = temp;
    }
    delete head;
}
int SingleCircularLinkedList::length() const
{
    return count;
}
void SingleCircularLinkedList::get_element(const int i, int &x) const
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
Node *SingleCircularLinkedList::locate(const int x) const
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
void SingleCircularLinkedList::insert_element(const int i, const int x)
{
    if (i < 1 || i > count + 1)
    {
        cout << " range_error!" << endl;
        return;
    }
    Node *current = head;
    int j = 0;
    while (j != i - 1)
    {
        j++;
        current = current->next;
    }
    Node *newnode = new Node;
    newnode->data = x;
    newnode->next = current->next;
    current->next = newnode;
    if (i == count + 1)
    {
        rear = newnode;
    }
    count++;
}
void SingleCircularLinkedList::delete_element(const int i)
{
    if (i < 1 || i > count + 1)
    {
        cout << " range_error!" << endl;
        return;
    }
    int j = 0;
    Node *current = head;
    while (j != i - 1)
    {
        j++;
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    if (current->next == head)
    {
        rear = current;
    }
    count--;
}
Node *SingleCircularLinkedList::get_head()
{
    return head;
}
Node *SingleCircularLinkedList::get_rear()
{
    return rear;
}
void SingleCircularLinkedList::create_R()
{
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
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
        count++;
    }
}
void SingleCircularLinkedList::print() const
{
    Node *current = head->next;
    while (current != head)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
