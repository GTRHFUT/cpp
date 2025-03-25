#pragma once

struct Node{
    int data;
    Node* next;
};

class List{
private:
    Node* head;
public:
    List();
    ~List();
    Node* get_head()const;
    void create_R();
    void print()const;
};