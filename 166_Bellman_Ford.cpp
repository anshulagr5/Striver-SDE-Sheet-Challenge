#include <bits/stdc++.h> 
using namespace std;

int bellmonFord(int vertices, int m, int source, int dest, vector<vector<int>> &vec) {
    vector<int>ans(vertices+1,1e9);
    ans[source]=0;
    vector<bool>in_queue(vertices+1,false);
    vector<vector<pair<int,int>>>adj(vertices+1);
    for(auto it:vec){
        adj[it[0]].push_back({it[1],it[2]});
    }
    
    queue<int>q;
    q.push(source);
    in_queue[source]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        in_queue[u]=false;
        for(auto it:adj[u]){
            int v=it.first;
            int d2=it.second;
            if(ans[u]+d2<ans[v]){
                ans[v]=ans[u]+d2;
                if(!in_queue[v]){
                 q.push(v);
                 in_queue[v]=true;
                }
            }
        }
    }
    return ans[dest];

} 
