#include"MergeSort.h"
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int k = left;
    int *temp1 = new int[n1];
    int *temp2 = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        temp1[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        temp2[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (temp1[i] < temp2[j])
            arr[k++] = temp1[i++];
        else if (temp1[i] >= temp2[j])
            arr[k++] = temp2[j++];
    }
    while (i < n1)
        arr[k++] = temp1[i++];
    while (j < n2)
        arr[k++] = temp2[j++];
    delete[] temp1;
    delete[] temp2;
}

void MergeSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}