#pragma once
void Delete_Duplication(int arr[], int n){
    int i,j;
    j = 0;
    for(i = 1; i < n; i++){
        if(arr[j] != arr[i] && (j + 1) != i){
            j++;
            arr[j] = arr[i];
        }
    }
}