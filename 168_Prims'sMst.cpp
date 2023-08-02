#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>>adj[n+1];

    for(auto it:g){
      adj[it.first.first].push_back({it.first.second, it.second});
      adj[it.first.second].push_back({it.first.first,it.second});
    }
    
    vector<pair<pair<int,int>,int>> ans;
    vector<bool>visited(n+1,false);
    
    priority_queue< pair<int,pair<int,int>>,vector< pair<int,pair<int,int>>>,
    greater< pair<int,pair<int,int>>>>q;
    q.push({0,{1,-1}});

    while(q.size()!=0)
    {
        int currnode=q.top().second.first;
        int parentnode=q.top().second.second;
        int wt=q.top().first;

        q.pop(); //remove
        
        if(visited[currnode])continue;
        visited[currnode]=true; //mark

        if(parentnode!=-1){
          ans.push_back({{parentnode, currnode}, wt}); //work
        }
        for(auto it:adj[currnode]){
            if(!visited[it.first]){
                q.push({it.second,{it.first,currnode}}); //add
            }
        }
    }
    return ans;

}
