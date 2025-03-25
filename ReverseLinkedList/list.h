#pragma once

struct Node{
    int data;
    Node* next;
};

class list{
private:
    int count;
    Node* head;
public:
    list();
    ~list();
    Node* get_head();
    void create_R();
    void print()const;
};