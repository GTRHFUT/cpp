// 将下面递归程序转换为等价的非递归程序。
// void P(int n)
// {
//     if (n > 0)
//     {
//         cout << n;
//         P(n - 1);
//         P(n - 1);
//     }
// }

#include <iostream>
#include <stack>
using namespace std;
void p(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        p(n - 1);
        p(n - 1);
    }
}

void pp(int n)
{
    stack<int> s;
    while (n > 0 || !s.empty())
    {
        while (n > 0)
        {
            cout << n << " ";
            s.push(n);
            n--;
        }
        if (!s.empty())
        {
            n = s.top();
            s.pop();
            n--;
        }
    }
}
int main()
{
    p(3);
    cout << endl;
    pp(3);
    cout << endl;
    system("pause");
    return 0;
}