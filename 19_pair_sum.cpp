#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
     sort(arr.begin(),arr.end());
     int low=0;
     int high=arr.size()-1;
     vector<vector<int>>ans;
     while(low<high)
     {
         if(arr[low]+arr[high]==s)
         {
             int prev_high=high;
             while (low < high && arr[high] == arr[prev_high]) {
               ans.push_back({arr[low],arr[prev_high]});
               high--;
             }
             high=prev_high;
             low++;
            
         }
         else if(arr[low]+arr[high]>s)high--;
         else low++;
     }
     return ans;
}
