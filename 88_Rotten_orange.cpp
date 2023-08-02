#include<bits/stdc++.h>
using namespace std;


int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int total=0;
    int rotten=0;
    queue<pair<int,int>>q;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(grid[i][j]!=0)total++;
           if(grid[i][j]==2){rotten++;q.push({i,j});}
        }
    }
    int count=0,time=0;

    int dx[]={0,-1,0,+1};
    int dy[]={+1,0,-1,0};

    while(!q.empty())
    {
        int k=q.size();
        count+=k;

        while(k--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];

                if(newx<0||newx>=n || newy<0 || newy>=m || grid[newx][newy]!=1)
                  continue;
                grid[newx][newy]=2;
                q.push({newx,newy});
            }
        }
        if(!q.empty())time++;
    }
   return count==total?time:-1;

}
