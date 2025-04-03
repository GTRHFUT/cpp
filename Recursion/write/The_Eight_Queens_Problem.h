// 八皇后问题：设计算法在国际象棋棋盘上放置八个皇后, 以使其中任意两个不能互相吃掉对方。
// 解：由国际象棋的规则可知，在棋盘的每行、每列及每条对角线上只能放置一个棋子方能满足上述条件。
// 因此，本题可这样进行：依次在每行（列）中试探着找一个合适的位置来放置棋子（此处不妨逐列试探），
// 要求能和已放置的棋子相容，然后再继续往下搜索。
// 重复这一操作过程，直到所放棋子满足条件为止。
#pragma once
#include <iostream>
int count;
const void print_Queen(int arr[], int n)
{
    std::cout << "(";
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            std::cout << arr[i];
            break;
        }
        std::cout << arr[i] << ",";
    }
    std::cout << ")" << std::endl;
}

// 检查放在第i行第j列是否可以(n为矩阵的行列数)
bool ok(int arr[], int i, int j, int n)
{
    int ii, jj;
    bool isOk;
    ii = i, jj = j, isOk = true;
    // 判断第i行是否可以放置(即是否有元素在这行)
    while (jj > 1 && isOk)
    {
        jj--;
        isOk = arr[jj] != i;
    }
    // 检查左对角线是否有元素
    jj = j;
    while (jj > 1 && ii > 1 && isOk)
    {
        jj--, ii--;
        isOk = arr[jj] != ii;
    }
    // 检查右对角线是否有元素
    jj = j, ii = i;
    while (jj > 1 && ii < n && isOk)
    {
        jj--, ii++;
        isOk = arr[jj] != ii;
    }
    return isOk;
}

// 存放行序的数组，数组的下标含义为列序，j用来控制列数, n为矩阵的行列数 + 1
void Queen(int arr[], int j, int n)
{
    if (j >= n)
    {
        print_Queen(arr, n);
        ::count++;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (ok(arr, i, j, n - 1))
        {
            arr[j] = i;
            Queen(arr, j + 1, n);
        }
    }
}