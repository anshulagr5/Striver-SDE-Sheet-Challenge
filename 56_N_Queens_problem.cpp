#include<bits/stdc++.h>
using namespace std;


void helper(vector<vector<int>>&ans,vector<vector<int>>chess,int j,
vector<int>samerow,vector<int>updiagonal,vector<int>downdiagonal)
{
    int n=chess.size();
    if(j==n)
    {
        vector<int>temp;
        for(auto it:chess)
        {
            for(auto c:it)
            {
                temp.push_back(c);
            }
        }
        ans.push_back(temp);
    }
    
    for(int i=0;i<n;i++)
    {
        if(samerow[i]==0 && updiagonal[n-1+j-i]==0 && downdiagonal[i+j]==0){
            samerow[i]=1;
            updiagonal[n-1+j-i]=1;
            downdiagonal[i+j]=1;
            chess[i][j]=1;
            helper(ans,chess,j+1,samerow,updiagonal,downdiagonal);
            chess[i][j]=0;
            samerow[i]=0;
            updiagonal[n-1+j-i]=0;
            downdiagonal[i+j]=0;
        }
    }
    
}
vector<vector<int>> solveNQueens(int n) {
  vector<vector<int>> chess(n, vector<int>(n, 0));
   vector<vector<int>> ans;
   vector<int>samerow(n,0);
   vector<int>updiagonal(2*n-1,0);
   vector<int>downdiagonal(2*n-1,0);
   helper(ans, chess,0,samerow,updiagonal,downdiagonal);
   return ans;
}
