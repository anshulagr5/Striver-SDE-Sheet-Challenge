#include <bits/stdc++.h> 
using namespace std;

void bfs(vector<vector<int>>adj,vector<bool>&visited,vector<int>&ans,int node)
{
    queue<int>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            int node=q.front();
            ans.push_back(node);
            q.pop();
           for(int j=0;j<adj[node].size();j++){
             if (!visited[adj[node][j]]) {
               q.push(adj[node][j]);
               visited[adj[node][j]]=true;
             }
           }
        }
    }

}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<vector<int>>adj(vertex);

    for(auto it:edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    for(int i=0;i<vertex;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    vector<int>ans;
    vector<bool>visited(vertex,false);

    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }
    return ans;
}
