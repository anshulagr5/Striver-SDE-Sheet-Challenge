#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>adj,vector<bool>&visited,int node)
{
    queue<pair<int,int>>q;
    q.push({node,-1});
    visited[node]=true;
    while(!q.empty())
    {
        int node=q.front().first;
        int par=q.front().second;
          q.pop();
        for(auto it:adj[node]){
           if(!visited[it]){
               visited[it]=1;
               q.push({it,node});
           }
           else if(it!=par){
               return true;
           }
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
        if(!visited[i] &&bfs(adj,visited,i))
            return "Yes";
    }
    return "No";
}
