#include <bits/stdc++.h> 
vector<vector<int>>helper(int n, vector<int>&arr)
{
   if(n==1)return {{},{arr[0]}};
  
    vector<vector<int>>temp=helper(n-1,arr);
    vector<vector<int>>ans=temp;
    for (int j = 0; j < temp.size(); j++) {
      temp[j].push_back(arr[n-1]);
     if(find(ans.begin(),ans.end(),temp[j])==ans.end()) ans.push_back(temp[j]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
   sort(arr.begin(),arr.end());
   return helper(n,arr);
}
