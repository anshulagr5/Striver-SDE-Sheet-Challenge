#include <bits/stdc++.h>

bool dfs(vector<vector<int>>adj,vector<int>&color,int col,int node)
{
    color[node]=col;
    for(auto it:adj[node]){
        if(color[it]==-1){
          if(!dfs(adj,color,!col,it))return false;
        }
        else if(color[it]==col)return false;
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n=edges.size();
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
   
    vector<int>color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(!dfs(adj,color,0,i))return false;
        }
    }
    return true;


}
