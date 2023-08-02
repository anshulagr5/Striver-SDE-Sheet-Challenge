#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    priority_queue<pair<int,int>>pq;
    unordered_map<int,int>umap;
    for(auto it:arr)
       umap[it]++;
    for(auto it:umap)
        pq.push({it.second,it.first});
    vector<int>ans;
    while(k-- && pq.size()!=0)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
