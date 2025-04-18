#include <iostream>
using namespace std;

int search(int nums[], int n, int target)
{
    int right = n - 1;
    int left = 0;
    
    while(left <= right){
        int mid = (right + left) / 2;  
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;  
    }
    return left;  
}
int main()
{
    int n, target;
    cout << "Please enter the numbers of array: " << endl;
    cin >> n;
    int *nums = new int[n];
    cout << "Please enter the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Please enter the target: " << endl;
    cin >> target;
    cout << search(nums, n, target) << endl;
    delete[] nums;
    system("pause");
    return 0;
}