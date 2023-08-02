#include<bits/stdc++.h>
using namespace std;

int helper(int n,int arr[],int prev)
{
    if(prev==n-1)return 1;
    int ans=0;
    if(arr[prev+1]<arr[prev]){
       ans=1+helper(n,arr,prev+1);
    }
    else{
       ans=helper(n,arr,prev+1);
    }
    return ans;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    int ans=INT_MIN;
   for(int i=0;i<n;i++)
   {
       int find=helper(n,arr,i);
       ans=max(ans,find);
   }
   return ans;
}

     
