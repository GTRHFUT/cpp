#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

struct Node
{
    int data;
    Node *next;
};
class SingleCircularLinkedList
{
private:
    int count;
    Node *head, *rear;

public:
    SingleCircularLinkedList();
    ~SingleCircularLinkedList();
    int length() const;
    void get_element(const int i, int &x) const;
    Node *locate(const int x) const;
    void insert_element(const int i, const int x);
    void delete_element(const int i);
    Node *get_head();
    Node *get_rear();
    void create_R();
    void print() const;
};
#endif