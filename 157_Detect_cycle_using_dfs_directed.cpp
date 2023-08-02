
#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>adj,int node,vector<bool>&visited,vector<bool>&path )
{
  visited[node]=true;
  path[node]=true;
  for(auto it:adj[node]){
   if(visited[it] && path[it])return 1;
   else{
     if(!visited[it] && dfs(adj,it,visited,path))return 1;
   }
  }
  path[node]=false;
  return 0;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   vector<vector<int>>adj(n+1);
   for(auto it:edges){
     adj[it.first].push_back(it.second);
   }
   vector<bool>visited(n+1,false);
   vector<bool>path(n+1,false);
   for(int i=1;i<=n;i++){
     if(!visited[i] && dfs(adj,i,visited,path)){
       return 1;
     }
   }
   return 0;
}
