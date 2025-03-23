#include <iostream>
#include "list.h"
#include <limits>
using namespace std;

list::list()
{
    count = 0;
}
int list::length() const
{
    return count;
}
void list::get_element(const int i, int &x) const
{
    if (i < 1 || i > count)
    {
        cout << "out_of_range!" << endl;
        return;
    }
    x = data[i - 1];
}
int list::locate(const int x) const
{
    for (int i = 0; i < count; i++)
    {
        if (x == data[i])
            return i + 1;
    }
    return -1;
}
void list::insert_element(const int i, const int x)
{
    if (count == MAXLEN)
    {
        cout << "List is full!" << endl;
        return;
    }
    if (i < 1 || i > count + 1)
    {
        cout << "out_of_range!" << endl;
        return;
    }
    for (int j = count - 1; j >= i - 1; j--)
        data[j + 1] = data[j];
    data[i - 1] = x;
    count++;
}
void list::delete_element(const int i)
{
    if (count == 0)
    {
        cout << "List is empty!" << endl;
        return;
    }
    if (i < 1 || i > count)
    {
        cout << "out_of_range!" << endl;
        return;
    }
    for (int j = i - 1; j < count - 1; j++)
        data[j] = data[j + 1];
    count--;
}
void list::createlist()
{
    int x;
    cout << "Enter the Elements(End: Please enter -1!): " << endl;
    while (count <= MAXLEN)
    {
        cin >> x;
        if (x == -1)
            return;
        if (cin.fail())
        {
            // 重置输入流（cin）的错误状态。当输入发生错误（如输入非数字内容到 int 变量），cin 会标记错误状态并停止工作，
            // clear() 清除该错误标记，让输入流恢复正常，以便后续重新输入
            cin.clear();
            // numeric_limits<streamsize>::max()：获取输入流缓冲区可处理的最大字符数，确保彻底清空缓冲区
            // ignore(...)：忽略输入缓冲区中的字符，直到遇到换行符（\n）。这一步清空之前错误的输入内容，
            // 避免残留数据影响后续输入
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Incorrect input, please Re_Enter!" << endl;
            continue;
        }
        data[count++] = x;
    }
}
void list::printlist() const
{
    for (int i = 0; i < count; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}