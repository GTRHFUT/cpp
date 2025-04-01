// 给你一个大小为 m x n的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
// 示例1：
// 输入：
// 1 2 3
// 4 5 6
// 7 8 9
// 输出：
// 1 2 4 7 5 3 6 8 9

// 示例2：
// 输入：
// 1 2 3 4 5
// 6 7 8 9 10
// 输出：
// 1 2 6 7 3 4 8 9 5 10

#include <iostream>
using namespace std;
void DiagonalTraversal(int mat[][100], int m, int n, int arr[])
{
    int length = 0;
    //一条对角线的x坐标和y坐标之和
    int sum = m - 1 + n - 1;
    //遍历每条对角线
    for (int i = 0; i <= sum; i++)
    {
        //如果对角线的x坐标和y坐标之和是偶数，则从左下角到右上角遍历
        if (i % 2 == 0)
        {
            //控制x坐标的范围，并计算y坐标
            for (int j = i; j >= 0; j--)
            {
                //如果x坐标在范围内，并且y坐标在范围内
                if (j < m && i - j < n)
                {
                    arr[length] = mat[j][i - j];
                    length++;
                }
            }
        }
        //如果对角线的x坐标和y坐标之和是奇数，则从右上角到左下角遍历
        else
        {
            //控制y坐标的范围，并计算x坐标
            for (int j = i; j >= 0; j--)
            {
                //如果y坐标在范围内，并且x坐标在范围内
                if (j < n && i - j < m)
                {
                    arr[length] = mat[i - j][j];
                    length++;
                }
            }
        }
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int m, n;
    cout << "Enter rows and cols : " << endl;
    cin >> m >> n;
    int mat[100][100];
    cout << "Enter elements of array : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    int arr[100];
    DiagonalTraversal(mat, m, n, arr);
    print(arr, m * n);
    system("pause");
    return 0;
}