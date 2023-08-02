#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

    unordered_map<int,int>umap;
    int ans=0;
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
       sum+=arr[i];
       if(sum==0)ans=i+1;
       if(umap.find(sum)!=umap.end())
       {
          ans=max(ans,i-umap[sum]);
       }
       else umap[sum]=i;
       
    }
    return ans;

}
