#include <iostream>
#include "list.h"
using namespace std;

list::list()
{
    count = 0;
    head = new Node;
    head->next = nullptr;
}
list::~list()
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
Node *list::get_head()
{
    return head;
}
void list::create_R()
{
    Node *rear = head;
    int x;
    cout << "Enter the Elements(End: Please enter > 100 OR < -100!): " << endl;
    while (true)
    {
        cin >> x;
        if (x > 100 || x < -100)
            return;
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
        count++;
        if (count >= 300)
            return;
    }
}
void list::print() const
{
    Node *current = head->next;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
