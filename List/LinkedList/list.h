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
    int length()const;
    void get_element(const int i, int& x)const;
    Node* locate(const int x)const;
    void insert_element(const int i, const int x);
    void delete_element(const int i);
    Node* get_head();
    void create_R();
    void create_H();
    void print()const;
};