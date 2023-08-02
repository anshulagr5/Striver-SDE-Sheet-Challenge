#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>indegree(v);
    vector<int>adj[v];
    for(auto it:edges){
       adj[it[0]].push_back(it[1]);
    }

    for(auto it:adj){
        for(auto x:it){
            indegree[x]++;
        }
    }
    queue<int>q;

    for(int i=0;i<v;i++){
      if(indegree[i]==0)q.push(i);
    }
    vector<int>top;
    while(!q.empty())
    {
        int node=q.front();
        top.push_back(node);
        q.pop();
        for(auto x:adj[node]){
            indegree[x]--;
            if(indegree[x]==0)q.push(x);
        }
    }
    return top;
}
