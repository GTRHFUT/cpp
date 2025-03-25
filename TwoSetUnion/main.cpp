#include <iostream>
#include "list.h"
using namespace std;

void Union(const List &A, const List &B, List &C)
{
    Node *current_A = A.get_head()->next;
    Node *current_B = B.get_head()->next;
    Node *current_C = C.get_head();
    int x;
    while (current_A != nullptr && current_B != nullptr)
    {
        if (current_A->data < current_B->data)
        {
            x = current_A->data;
            Node *newnode = new Node;
            newnode->data = x;
            newnode->next = nullptr;
            current_C->next = newnode;
            current_C = newnode;
            current_A = current_A->next;
        }
        else if (current_A->data > current_B->data)
        {
            x = current_B->data;
            Node *newnode = new Node;
            newnode->data = x;
            newnode->next = nullptr;
            current_C->next = newnode;
            current_C = newnode;
            current_B = current_B->next;
        }
        else
        {
            x = current_A->data;
            Node *newnode = new Node;
            newnode->data = x;
            newnode->next = nullptr;
            current_C->next = newnode;
            current_C = newnode;
            current_A = current_A->next;
            current_B = current_B->next;
        }
    }
    while (current_A != nullptr)
    {
        x = current_A->data;
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = nullptr;
        current_C->next = newnode;
        current_C = newnode;
        current_A = current_A->next;
    }
    while (current_B != nullptr)
    {
        x = current_B->data;
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = nullptr;
        current_C->next = newnode;
        current_C = newnode;
        current_B = current_B->next;
    }
}
int main()
{
    int n;
    List A, B;
    cin >> n;
    List *arr_C = new List[n];
    for (int i = 0; i < n; i++)
    {
        A.create_R();
        B.create_R();
        Union(A, B, arr_C[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr_C[i].print();
    }
    system("pause");
    return 0;
}