#include <bits/stdc++.h> 

void dfs(vector<int>adj[],vector<bool>&visited,int node,stack<int>&st){
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[it])dfs(adj,visited,it,st);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>adj[v];
    for(auto it:edges){
       adj[it[0]].push_back(it[1]);
    }

    vector<bool>visited(v,false);
    stack<int>st;
    vector<int>ans;

    for(int i=0;i<v;i++){
        if(!visited[i])dfs(adj,visited,i,st);
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
