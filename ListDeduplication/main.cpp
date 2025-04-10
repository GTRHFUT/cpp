#include <iostream>
#include "list.h"
void Deduplicate(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    // 目前的结点和下一个结点的值是否相同
    bool is = false;
    // 指向前一个结点的指针
    Node *prev = head;
    // 指向目前结点的指针
    Node *current = head->next;
    while (current->next != nullptr)
    {
        // 指向下一个结点的指针
        Node *temp = current->next;
        // 目前结点的值和下一个结点的值相同
        if (current->data == temp->data)
        {
            is = true;
            current = current->next;
            prev->next = nullptr;
        }
        // 目前结点的值和下一个结点的值不同
        else
        {
            if (!is)
            {
                prev = current;
                current = current->next;
            }
            // 如果前面刚存在相同
            else
            {
                current = current->next;
                prev->next = current;
                is = false;
            }
        }
    }
}
int main()
{
    list l;
    l.create_R();
    Deduplicate(l.get_head());
    l.print();
    system("pause");
    return 0;
}