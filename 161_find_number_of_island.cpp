#include<bits/stdc++.h>
using namespace std;

void helper(int **arr,vector<vector<bool>>&visited,int x,int y){
   int n=visited.size();
   int m=visited[0].size();
   visited[x][y]=true;
   int Dx[]={1,0,-1,0,1,-1,1,-1};
   int Dy[]={0,1,0,-1,1,-1,-1,1};

   for(int k=0;k<8;k++){
      int newx=x + Dx[k];
      int newy=y + Dy[k];
      if(newx>=0 && newx<n && newy>=0 && newy<m && 
      arr[newx][newy]==1 && !visited[newx][newy]){
         helper(arr,visited,newx,newy);
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<bool>>visited(n,vector<bool>(m,false));
   int count=0;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if (arr[i][j] == 1 && !visited[i][j]) {
          helper(arr, visited,i,j);
          count++;
        }
      }
   }
   return count;
}
