#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int>ans;
    unordered_map<int,int>umap;
    for(int i=0;i<k;i++)umap[arr[i]]++;
    ans.push_back(umap.size());
     for(int i=k;i<arr.size();i++)
     {
         if(--umap[arr[i-k]]==0)umap.erase(arr[i-k]);
         umap[arr[i]]++;
         ans.push_back(umap.size());
     }
     return ans;
}
