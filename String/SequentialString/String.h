#pragma once
#define MAXLEN 100
class String
{
private:
    int count;
    char data[MAXLEN];

public:
    // 初始化
    String();
    String(const char arr[]);
    // 复制构造
    String(const String &other);
    // 赋值
    String& operator=(const String &s);
    //求长度
    int Length() const;
    // 连接(两串连接后形成的新串)
    String Strcat(const String &s) const;
    // 求子串(从序号i开始的j个字符形成的子串)
    String substr(const int i, const int j) const;
    // 串比较
    int Strcmp(const String &s) const;
    // 插入(将子串S1插入到串S的从第i个字符开始的位置上)
    void Insert(const int &i, const String &s);
    // 删除(删除串S中从第i个字符开始的len个字符)
    void Deletestr(const int &i, const int &len);
    // 打印串
    void print()const;
};