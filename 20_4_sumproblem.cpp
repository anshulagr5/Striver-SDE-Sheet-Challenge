#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            int low=j+1;
            int high=n-1;
            int sum=target-arr[i]-arr[j];
            while(low<high)
            {
                if(arr[low]+arr[high]==sum)return "Yes";
                else if(arr[low]+arr[high]>sum)high--;
                else low++;
            }
        }
    }
    return "No";
}
