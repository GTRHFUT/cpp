#include <iostream>
#include "list.h"
using namespace std;

void ReverseLinkedList(Node *head, int k)
{
    if (k < 0 || k > 2 * 109 || head == nullptr || head->next == nullptr)
        return;
    //链表长度
    Node *current = head->next;
    Node *rear = head;
    int count = 0;
    while (current != nullptr)
    {
        count++;
        rear = current;
        current = current->next;
    }
    //如果移动位数为链表长度的倍数，就不需要移动
    if (k % count == 0)
        return;
    
    k = k % count;

    //找出要移动的起始结点
    int index = 0;
    Node *p = head;
    while (index < count - k)
    {
        index++;
        p = p->next;
    }
    //将移动的起始结点和head的next指针相连
    Node *temp = head->next;
    head->next = p->next;
    p->next = nullptr;
    //将移动的末尾结点和当初head的下一个结点相连
    rear->next = temp;
}
int main()
{
    //移动位数，结束标志
    int k, flag;
    list l;
    //循环输入进行测试
    while (true)
    {
        l.create_R();
        cin >> k;
        ReverseLinkedList(l.get_head(), k);
        l.print();
        cout << "Continue Or End(1 or -1)" << endl;
        cin >> flag;
        if (flag == -1)
            break;
        else if (flag != 1)
        {
            cout << "Input Error, Please re_enter !" << endl;
        }
    }
    system("pause");
    return 0;
}