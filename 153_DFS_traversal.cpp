#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>v,vector<bool>&visited,vector<int>&temp,int i){
    temp.push_back(i);
    visited[i]=true;
    for(int j=0;j<v[i].size();j++){
        if(!visited[v[i][j]]){
            dfs(v,visited,temp,v[i][j]);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>>v(V);
   for(int i=0;i<E;i++)
   {
       v[edges[i][0]].push_back(edges[i][1]);
       v[edges[i][1]].push_back(edges[i][0]);
   }

   vector<bool>visited(V,false);
   vector<vector<int>>ans;
  

   for(int i=0;i<V;i++){
      if(!visited[i]){
          vector<int>temp;
          dfs(v,visited,temp,i);
          ans.push_back(temp);
      }
   }
   return ans;
}
