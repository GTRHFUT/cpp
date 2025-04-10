#include <iostream>
#include <windows.h>
#include "sum.h"
#include "print.h"
#include "YangHuiTriangle.h"
#include "hanio.h"
#include "bag_method_1.h"
#include "bag_method_2.h"
#include "powerset.h"
#include "combination.h"
#include "arrange.h"
#include "The_Eight_Queens_Problem.h"
#include "Rabbit_breeding.h"
#include "Ack.h"
using namespace std;
int main()
{
    SetConsoleOutputCP(65001);
    int arr_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr_1) / sizeof(arr_1[0]);
    cout << "数组求和: " << endl;
    cout << sum(arr_1, n) << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "打印：" << endl;
    print(5);
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "杨辉三角: " << endl;
    printYangHuiTriangle(5);
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "汉诺塔: " << endl;
    hanio(3, 'A', 'B', 'C');
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "背包问题_方法一: " << endl;
    int w[] = {29, 26, 18, 16, 13, 10, 8, 5, 3, 1};
    n = sizeof(w) / sizeof(w[0]);
    bags bags[n];
    bag(w, n, 50, 0, bags, 0, 0);
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "背包问题_方法二: " << endl;
    int B[n];
    Bag(w, n - 1, 50, B, 0, 0, 0);
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "1 ~ 4的幂集: " << endl;
    int arr_2[4];
    PowerSet(arr_2, 0, 0, 4);
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "集合{1, 2, 3, 4}中取2个元素的所有组合" << endl;
    int arr_3[2];
    combination(arr_3, 1, 2, 2, 4);
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "集合{1, 2, 3, 4}中取2个元素的所有排列" << endl;
    int arr_4[2];
    bool used[4 + 1]{false};
    arrange(arr_4, 1, 2, 2, 4, used);
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "八皇后问题: " << endl;
    int arr_5[9];
    Queen(arr_5, 1, 9);
    cout << ::count << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "第3年每个月的兔子数目: " << endl;
    for (int i = 1; i <= 12; i++)
    {
        cout << "第" << i << "月: " << fibonacci(2 * 12 + i) << endl;
    }
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "Ack(5) = " << Ack(2, 3) << endl;
    cout << "Ack(5) = " << ack(2, 3) << endl;
    system("pause");
    return 0;
}
