#include <iostream>
#include "String.h"
using namespace std;
int main()
{
    String s1("Hello"), s2(","), s3("world"), s4;
    cout << s1.Length() << endl;
    s4 = s1;
    s4.print();
    s4 = s1.Strcat(s2).Strcat(s3);
    s4.print();
    cout << s4.Length() << '=' << s1.Length() << '+' << s2.Length() << '+' << s3.Length() << endl;
    s4 = s4.substr(1,5);
    s4.print();
    cout << s1.Strcmp(s2) << endl;
    cout << s1.Strcmp(s3) << endl;
    cout << s1.Strcmp(s4) << endl;
    s3.Insert(1,s2);
    s3.Insert(1,s4);
    s3.print();
    s3.Deletestr(5,4);
    s3.print();
    system("pause");
    return 0;
}