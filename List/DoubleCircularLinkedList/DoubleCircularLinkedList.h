#ifndef DOUBLECIRCULARLINKEDLIST_H
#define DOUBLECIRCULARLINKEDLIST_H
struct Node
{
    int data;
    Node *prior, *next;
};
class DoubleCircularLinkedList
{
private:
    int count;
    Node *head;
public:
    DoubleCircularLinkedList();
    ~DoubleCircularLinkedList();
    int length() const;
    void get_element(const int i, int &x) const;
    Node *locate(const int x) const;
    void insert_element(const int i, const int x);
    void delete_element(const int i);
    Node *get_head();
    void create_R();
    void print() const;
};
#endif
