#include<bits/stdc++.h>
using namespace std;

bool iscoloringsafe(int node,vector<vector<int>>&mat,int n,vector<int>color,int k)
{
    for(int i=0;i<n;i++)
    {
        if(i!=node && mat[i][node]==1 && color[i]==k)return false;
    }
    return true;
}
bool helper(int node,vector<vector<int>>&mat,int m,int n,vector<int>color)
{
    if(node==n)return true;
    for(int i=1;i<=m;i++)
    {
        if(iscoloringsafe(node,mat,n,color,i)){
            color[node]=i;
            if(helper(node+1,mat,m,n,color))return true;
            color[node]=0;
        }
    }
   return false;
}


string graphColoring(vector<vector<int>> &mat, int m) {
    int n=mat.size();
    vector<int>color(n,0);
    bool check=helper(0,mat,m,n,color);
    if(check)return "YES";
    return "NO";
}
