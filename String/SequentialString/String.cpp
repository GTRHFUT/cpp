#include <iostream>
#include "String.h"
using namespace std;
// 初始化
String::String()
{
    count = 0;
}
String::String(const char arr[])
{
    count = 0;
    while (arr[count] != '\0')
    {
        data[count] = arr[count];
        count++;
        if (count == MAXLEN - 1)
        {
            cout << "String is full!" << endl;
            break;
        }
    }
}
// 复制构造
String::String(const String &other)
{
    count = other.count;
    for (int i = 0; i < count; i++)
    {
        data[i] = other.data[i];
    }
}
// 赋值
String &String::operator=(const String &s)
{
    if (this != &s)
    {
        count = s.count;
        for (int i = 0; i < count; i++)
        {
            data[i] = s.data[i];
        }
    }
    return *this;
}
// 求长度
int String::Length() const
{
    return count;
}
// 连接(两串连接后形成的新串)
String String::Strcat(const String &s) const
{
    String ss;
    ss.count = count + s.count;
    if (ss.count > MAXLEN - 1)
    {
        cout << "The size of new String is over the range!" << endl;
        return "";
    }
    for (int i = 0; i < count; i++)
    {
        ss.data[i] = data[i];
    }
    for (int i = 0; i < s.count; i++)
    {
        ss.data[count + i] = s.data[i];
    }
    return ss;
}
// 求子串(从序号i开始的j个字符形成的子串)
String String::substr(const int i, const int j) const
{
    if (i + j - 1 > count)
    {
        cout << "The range of the substr exceeds the range of the parent string!" << endl;
        return "";
    }
    String ss;
    ss.count = j;
    for (int k = 0; k < ss.count; k++)
    {
        ss.data[k] = data[i - 1 + k];
    }
    return ss;
}
// 串比较
int String::Strcmp(const String &s) const
{
    int i = 0;
    while (i < count && i < s.count)
    {
        if (data[i] > s.data[i])
            return 1;
        else if (data[i] < s.data[i])
            return -1;
        else
            i++;
    }
    if (i == count)
    {
        if (i == s.count)
        {
            return 0;
        }
        return -1;
    }
    return 1;
}
// 插入(将子串s插入到串S的从第i个字符开始的位置上)
void String::Insert(const int &i, const String &s)
{
    if (count + s.count > MAXLEN - 1)
    {
        cout << "The size of new String is over the range!" << endl;
        return;
    }
    if(i > count){
        cout << "Insert position out of range!" << endl;
        return;
    }
    for (int j = count - 1; j >= i - 1; j--)
    {
        data[j + s.count] = data[j];
    }
    for (int j = 0; j < s.count; j++)
    {
        data[i - 1 + j] = s.data[j];
    }
    count += s.count;
}
// 删除(删除串S中从第i个字符开始的len个字符)
void String::Deletestr(const int &i, const int &len)
{
    if (i > count)
    {
        cout << "The starting position is out of range!" << endl;
        return;
    }
    if (i + len - 1 > count)
    {
        cout << "Delete digits out of range!" << endl;
        return;
    }
    for (int j = i - 1 + len; j < count; j++)
    {
        data[j - len] = data[j];
    }
    count -= len;
}
// 打印串
void String::print() const
{
    for (int i = 0; i < count; i++)
    {
        cout << data[i];
    }
    cout << endl;
}
