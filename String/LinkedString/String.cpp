#include <iostream>
#include "String.h"
using namespace std;

// 初始化
String::String()
{
    count = 0;
    head = new Node;
    head->next = nullptr;
}
String::String(const char arr[])
{
    count = 0;
    head = new Node;
    head->next = nullptr;

    Node *rear = head;
    while (arr[count] != '\0')
    {
        Node *newnode = new Node;
        newnode->ch = arr[count];
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
        count++;
    }
}
// 析构
String::~String()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current->next;
        delete current;
        current = temp;
    }
}
// 复制构造
String::String(const String &other)
{
    head = new Node;
    head->next = nullptr;

    Node *rear = head;
    Node *current_other = other.head->next;
    while (current_other != nullptr)
    {
        Node *newnode = new Node;
        newnode->ch = current_other->ch;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
        current_other = current_other->next;
    }
    count = other.count;
}
// 赋值
String &String::operator=(const String &other)
{
    Node *rear = head;
    Node *current_other = other.head->next;
    while (current_other != nullptr)
    {
        Node *newnode = new Node;
        newnode->ch = current_other->ch;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
        current_other = current_other->next;
    }
    count = other.count;
    return *this;
}
// 求长度
int String::Length() const
{
    return count;
}
// 连接(两串连接后形成的新串)
String String::Strcat(const String &s) const
{
    String ss;
    Node *current_this = head->next;
    Node *current_s = s.head->next;
    Node *rear = ss.head;
    while (current_this != nullptr)
    {
        Node *newnode = new Node;
        newnode->ch = current_this->ch;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
        current_this = current_this->next;
    }
    while (current_s != nullptr)
    {
        Node *newnode = new Node;
        newnode->ch = current_s->ch;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
        current_s = current_s->next;
    }
    ss.count = count + s.count;
    return ss;
}
// 求子串(从序号i开始的j个字符形成的子串)
String String::substr(const int i, const int j) const
{
    if (i + j - 1 > count)
    {
        cout << "The range of the substr exceeds the range of the parent string!" << endl;
        return "";
    }
    String ss;
    int start = 1;
    int num = 0;
    Node *current = head->next;
    Node *rear = ss.head;
    while (start != i && current != nullptr)
    {
        start++;
        current = current->next;
    }
    while (num != j && current != nullptr)
    {
        num++;
        Node *newnode = new Node;
        newnode->ch = current->ch;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
        current = current->next;
    }
    ss.count = j;
    return ss;
}
// 串比较
int String::Strcmp(const String &s) const
{
    Node *current_this = head->next;
    Node *current_s = s.head->next;
    while (current_this != nullptr && current_s != nullptr)
    {
        if (current_this->ch > current_s->ch)
            return 1;
        else if (current_this->ch < current_s->ch)
            return -1;
        else
        {
            current_this = current_this->next;
            current_s = current_s->next;
        }
    }
    if (current_this == nullptr)
    {
        if (current_s == nullptr)
            return 0;
        return -1;
    }
    return 1;
}
// 插入(将子串S1插入到串S的从第i个字符开始的位置上)
void String::Insert(const int &i, const String &s)
{
    Node *first_s = s.head->next;
    Node *current_s = s.head->next;
    Node *last_s;
    while (current_s != nullptr && current_s->next != nullptr)
    {
        current_s = current_s->next;
    }
    last_s = current_s;

    Node *current_this = head;
    int n = 0;
    while (n != i - 1 && current_this != nullptr)
    {
        n++;
        current_this = current_this->next;
    }
    Node *temp = current_this->next;
    current_this->next = first_s;
    last_s->next = temp;
    count += s.count;
}
// 删除(删除串S中从第i个字符开始的len个字符)
void String::Deletestr(const int &i, const int &len)
{
    if (i > count)
    {
        cout << "The starting position is out of range!" << endl;
        return;
    }
    if (i + len - 1 > count)
    {
        cout << "Delete digits out of range!" << endl;
        return;
    }
    Node *current = head;
    int n = 0;
    int delete_count = 0;
    Node* delete_ptr;
    while (n != i - 1 && current != nullptr)
    {
        n++;
        current = current->next;
    }
    delete_ptr = current->next;
    while(delete_count != len){
        delete_count++;
        Node* temp = delete_ptr ->next;
        delete delete_ptr;
        delete_ptr = temp;
    }
    current->next = delete_ptr;
    count-=len;
}
// 打印串
void String::print() const
{
    Node *current = head->next;
    while (current != nullptr)
    {
        cout << current->ch;
        current = current->next;
    }
    cout << endl;
}
