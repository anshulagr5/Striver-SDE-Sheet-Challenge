#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>adj,vector<bool>&visited,int node,int par)
{
    visited[node]=true;
    for(auto it:adj[node]){
      if (!visited[it]) {
          if(dfs(adj,visited,it,node)) return true;
      }
      else if(par!=it){
          return true;
      }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>>adj(n+1);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    vector<bool>visited(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i] &&dfs(adj,visited,i,-1))
            return "Yes";
    }
    return "No";
}
