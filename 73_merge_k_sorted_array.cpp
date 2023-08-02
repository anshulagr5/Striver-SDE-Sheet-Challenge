#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto it:kArrays)
    {
        for(auto c:it)pq.push(c);
    }
    vector<int>ans;
    while(pq.size()!=0)
    {
       ans.push_back(pq.top());
       pq.pop();
    }
    return ans;
}
