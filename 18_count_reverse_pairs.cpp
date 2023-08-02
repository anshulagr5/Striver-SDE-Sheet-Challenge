#include <bits/stdc++.h> 
using namespace std;

void merge(vector<int>&arr,int low,int mid,int high)
{
    vector<int>temp(high-low+1);
    int k=0;
    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])temp[k++]=arr[left++];
        else temp[k++]=arr[right++];
    }

    while(left<=mid)temp[k++]=arr[left++];
    while(right<=high)temp[k++]=arr[right++];

    for(int i=low;i<=high;i++)arr[i]=temp[i-low];

}

int countpairs_between_two_sortedarray(vector<int>&arr,int low, int mid ,int high)
{
    int right=mid+1;
    int count=0;
    for(int i=low;i<=mid;i++)
    {
        while(right<=high && arr[i]>2*arr[right])right++;
        count+=(right-(mid+1));
    }
    return count;
}

int calculateallpairs(vector<int>&arr,int low,int high)
{  
    int ans=0;
    if(high>low)
    {
        int mid;
        mid=(low)+(high-low)/2;
      
       // calculate all reversepairs of half of the array between (low) to (mid) indcluding(low and mid)
        ans+=calculateallpairs(arr,low,mid);
      
     //calculate all reversepairs of another half of the same array between (mid+1) to (high) including(mid+1 and high)
        ans+=calculateallpairs(arr,mid+1,high);
      
      //calculate reversepairs between two sorted array 
        ans+=countpairs_between_two_sortedarray(arr,low,mid,high);
      
      // merge the two sorted array
        merge(arr,low,mid,high);
    }
    return ans;
}

int reversePairs(vector<int> &arr, int n){
	return calculateallpairs(arr,0,n-1);
}
