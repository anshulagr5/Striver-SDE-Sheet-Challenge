#include <bits/stdc++.h> 


vector<int> dijkstra(vector<vector<int>> &vec,int vertices, int edges, int source) {
    vector<int>ans(vertices,INT_MAX);
    ans[0]=0;
    vector<int>parent(vertices);
    for(int i=0;i<vertices;i++)parent[i]=1;

    vector<vector<pair<int,int>>>adj(vertices);
    for(auto it:vec){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,source});
    while(!q.empty())
    {
        int d1=q.top().first;
        int u=q.top().second;
        q.pop();
        for(auto it:adj[u]){
            int v=it.first;
            int d2=it.second;
            if(d1+d2<ans[v]){
                ans[v]=d1+d2;
                parent[v]=u;
                q.push({d1+d2,v});
            }
        }
    }
    return ans;
}
