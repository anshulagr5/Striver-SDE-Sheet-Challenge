#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
    int ans=1,count=1;
    for(int i=0;i<n-1;i++)
    {
       
       while(i<n-1 && arr[i]==arr[i+1])i++;
       if(arr[i]+1==arr[i+1])count++;
       else{
           ans=max(ans,count);
           count=1;
       }
    }
    ans=max(ans,count);
    return ans;
}
