#include <iostream>
#include "list.h"
using namespace std;

void ReverseLinkedList(Node *head, int k)
{
    if (k < 0 || k > 2 * 109 || head == nullptr || head->next == nullptr)
        return;
    Node *current = head->next;
    Node *rear = head;
    int count = 0;
    while (current != nullptr)
    {
        count++;
        rear = current;
        current = current->next;
    }
    if (k % count == 0)
        return;
    k = k % count;

    int index = 0;
    Node *p = head;
    while (index < count - k)
    {
        index++;
        p = p->next;
    }
    Node *temp = head->next;
    head->next = p->next;
    p->next = nullptr;
    rear->next = temp;
}
int main()
{
    int k, flag;
    list l;
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