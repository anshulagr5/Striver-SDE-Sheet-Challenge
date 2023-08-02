#include<bits/stdc++.h>
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
   vector<int>prev(w+1,0);
   for(int W=weights[0];W<=w;W++)prev[W]=values[0];

   for(int ind=1;ind<n;ind++)
   {
      for(int W=w;W>=0;W--)
      {
         int right=prev[W];
         int left=INT_MIN;
         if(weights[ind]<=W)left=prev[W-weights[ind]]+values[ind];

          prev[W]=max(left,right);
      }
   }
   return prev[w];
}
