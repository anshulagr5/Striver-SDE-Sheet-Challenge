#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	vector<pair<int,int>>st;
      for(int i=0;i<matrix.size();i++)  
      {
          for(int j=0;j<matrix[0].size();j++)
          {
              if(matrix[i][j]==0)st.push_back({i,j});
          }
       }
        for(auto it:st)
        {
            for(int col=0;col<matrix[0].size();col++)
            {
                matrix[it.first][col]=0;
            }
            for(int row=0;row<matrix.size();row++)
            {
                matrix[row][it.second]=0;
            }
        }
        
}
