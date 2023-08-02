#include <bits/stdc++.h>

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n =edges.size();
  
    vector<int>adj[n];
    vector<int>color(n,-1);
  
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           if (edges[i][j]) {
           adj[i].push_back(j);
           adj[j].push_back(i);
          }
       }
    }

    queue<int>q;
    q.push(0);
    color[0]=0;

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {  
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node])return false;
            }
        }
    }
    return true;

}
