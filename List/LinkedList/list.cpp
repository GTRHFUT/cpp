#include <iostream>
#include "list.h"
#include <limits>
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
int list::length() const
{
    return count;
}
void list::get_element(const int i, int &x) const
{
    Node *current = head->next;
    int j = 1;
    while (current != nullptr && j != i)
    {
        current = current->next;
        j++;
    }
    if (current == nullptr)
    {
        cout << "range_error!" << endl;
        return;
    }
    x = current->data;
}
Node *list::locate(const int x) const
{
    Node *current = head->next;
    while (current != nullptr)
    {
        if (current->data == x)
            return current;
        else
            current = current->next;
    }
    return nullptr;
}
void list::insert_element(const int i, const int x)
{
    if (i < 1 || i > count + 1)
    {
        cout << "range_error!" << endl;
        return;
    }
    Node *current = head;
    int j = 0;
    while (current != nullptr && j != i - 1)
    {
        current = current->next;
        j++;
    }
    Node *newnode = new Node;
    newnode->data = x;
    newnode->next = current->next;
    current->next = newnode;
    count++;
}
void list::delete_element(const int i)
{
    if (i < 1 || i > count)
    {
        cout << "range_error!" << endl;
        return;
    }
    Node *current = head;
    int j = 0;
    while (j != i - 1 && current != nullptr)
    {
        current = current->next;
        j++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    temp = nullptr;
    count--;
}
Node *list::get_head()
{
    return head;
}
void list::create_R()
{
    Node *rear = head;
    int x;
    cout << "Enter the Elements(End: Please enter -1!): " << endl;
    while (true)
    {
        cin >> x;
        if (x == -1)
            return;
        if (cin.fail())
        {
            // 重置输入流（cin）的错误状态。当输入发生错误（如输入非数字内容到 int 变量），cin 会标记错误状态并停止工作，
            // clear() 清除该错误标记，让输入流恢复正常，以便后续重新输入
            cin.clear();
            // numeric_limits<streamsize>::max()：获取输入流缓冲区可处理的最大字符数，确保彻底清空缓冲区
            // ignore(...)：忽略输入缓冲区中的字符，直到遇到换行符（\n）。这一步清空之前错误的输入内容，
            // 避免残留数据影响后续输入
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Incorrect input, please Re_Enter!" << endl;
            continue;
        }
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
        count++;
    }
}
void list::create_H()
{
    int x;
    cout << "Enter the Elements(End: Please enter -1!): " << endl;
    while (true)
    {
        cin >> x;
        if (x == -1)
            return;
        if (cin.fail())
        {
            // 重置输入流（cin）的错误状态。当输入发生错误（如输入非数字内容到 int 变量），cin 会标记错误状态并停止工作，
            // clear() 清除该错误标记，让输入流恢复正常，以便后续重新输入
            cin.clear();
            // numeric_limits<streamsize>::max()：获取输入流缓冲区可处理的最大字符数，确保彻底清空缓冲区
            // ignore(...)：忽略输入缓冲区中的字符，直到遇到换行符（\n）。这一步清空之前错误的输入内容，
            // 避免残留数据影响后续输入
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Incorrect input, please Re_Enter!" << endl;
            continue;
        }
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = head->next;
        head->next = newnode;
        count++;
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
