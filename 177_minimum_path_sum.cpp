#include <bits/stdc++.h> 



//..........ITERATIVE APPROACH................

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();

    vector<int>prev(m),curr(m);
    prev[0]=grid[0][0];

    for(int i=1;i<m;i++)prev[i]=prev[i-1]+grid[0][i];

    for(int x=1;x<n;x++)
    {
        for(int y=0;y<m;y++)
        {
           
            int up =prev[y];
            int left=INT_MAX;
            if(y>0) left=curr[y-1];
            curr[y]=min(left,up)+grid[x][y];
        }
        prev=curr;
    }
    return prev[m-1];
}
