#include <bits/stdc++.h> 
using namespace std;

long long  merge(long long arr[],long long temp[], int left, int mid,int right)
{

    int i, j, k;
    long long inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count +(mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    
    while (j <= right)
        temp[k++] = arr[j++];
 

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}


long long  _mergeSort(long long arr[],long long temp[], int left, int right)
{
    int mid;
    long long inv_count = 0;
    if (right > left) {
        // Divide the array into two parts and
        // call _mergeSortAndCountInv()
        // for each of the parts
        mid = (right + left) / 2;
 
        // Inversion count will be sum of
        // inversions in left-part, right-part
        // and number of inversions in merging
        inv_count += _mergeSort(arr,temp, left, mid);
        inv_count += _mergeSort(arr,temp, mid + 1, right);
 
        // Merge the two parts
        inv_count += merge(arr,temp, left, mid + 1, right);
    }
    return inv_count;
}


long long getInversions(long long *arr, int n){
     long long temp[n];
     return _mergeSort(arr,temp,0,n-1);
}
