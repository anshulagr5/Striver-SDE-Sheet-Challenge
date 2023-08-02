#include <bits/stdc++.h> 
using namespace std;

void helper(vector<vector<pair<int,int>>>&ans,vector<pair<int,int>>temp,
vector<vector<int>>maze,int n,int i,int j)
{
     temp.push_back({i,j});
     maze[i][j]=0;

    if (i == n-1 && j == n-1) {
    ans.push_back(temp);
    return;
  }
    if(i+1<n && maze[i+1][j]==1)
       helper(ans,temp,maze,n,i+1,j);
    if(i-1>=0 && maze[i-1][j]==1)
       helper(ans,temp,maze,n,i-1,j);
    if(j-1>=0 && maze[i][j-1]==1)
       helper(ans,temp,maze,n,i,j-1);
    if(j+1<n && maze[i][j+1]==1)
       helper(ans,temp,maze,n,i,j+1);
     maze[i][j]=1;
     temp.pop_back();
} 
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<pair<int,int>>>ans;
  vector<pair<int,int>>temp;
  helper(ans,temp,maze,n,0,0);
  vector<vector<int>>res;
  for(int i=0;i<ans.size();i++)
  { 
    vector<int>temp(n*n,0);
    for(int j=0;j<ans[i].size();j++)
    {
       int index=ans[i][j].first*n +ans[i][j].second;
       temp[index]=1;
    }
    res.push_back(temp);
  }
  return res;
}
