#pragma once
#define MAXLEN 100
class list
{
private:
    int data[MAXLEN];
    int count;
public:
    list();     //初始化
    int length()const;      //求线性表的长度
    void get_element(const int i, int& x)const;     //按序号取元素
    int locate(const int x)const;       //按值查询，若查到，则返回序号，否则返回-1
    void insert_element(const int i, const int x);      //在指定位置插入元素
    void delete_element(const int i);               //删除指定序号的元素
    void createlist();      //创建线性表
    void printlist()const;      //打印线性表
};