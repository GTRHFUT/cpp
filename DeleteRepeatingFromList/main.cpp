// 由于题目对于移动次数的说明不太清楚，现有两种解决方案，每种的移动次数在特定情况下存在不同
// 例如：1 2 3 4 5  移动0次或4次

// 方案一
#include <iostream>
using namespace std;

void DeleteRepeatingElement(int arr[], int &n, int &moves)
{
    if (n == 0)
    {
        moves = 0;
        return;
    }

    // 移动次数置为0
    moves = 0;
    // 不重复元素的下标
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        // 如果遇到不重复元素
        if (arr[j] != arr[i])
        {
            j++;
            // 如果不重复元素就在要插入的下一位，就没不要移动
            // 如果不在，就移动3
            if (j != i)
            {
                arr[j] = arr[i];
                moves++;
            }
        }
    }
    n = j + 1;
}

int main()
{
    cout << "Method_1:" << endl;
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int moves = 0;
    DeleteRepeatingElement(arr, n, moves);

    // 输出结果
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 移动次数
    cout << moves << endl;

    delete[] arr;
    system("pause");
    return 0;
}





// 方案二
//  #include <iostream>
//  using namespace std;

// void DeleteRepeatingElement(int arr[], int &n)
// {
//     if (n == 0)return;
//     // i为数组元素下标，j为不重复元素的插入位置
//     int i = 0, j = 1;
//     while (i < n - 1)
//     {
//         if (arr[i] != arr[i + 1])
//         {
//             arr[j] = arr[i + 1];
//             j++;
//         }
//         i++;
//     }
//     //不重复的元素数目
//     n = j;
// }

// int main()
// {
//     cout << "Method_2:" << endl;
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     DeleteRepeatingElement(arr, n);

//     // 输出结果
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     // 移动次数
//      cout << n - 1 << endl;
//     delete[] arr;
//     system("pause");
//     return 0;
// }
