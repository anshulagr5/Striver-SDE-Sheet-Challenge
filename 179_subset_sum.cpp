bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector<bool>prev(k+1,false),curr(k+1);
   prev[0]=true;
   for(int i=1;i<=n;i++)
   {
       curr[0]=true;
       for(int j=1;j<=k;j++)
       {
           bool c1=prev[j];
           bool c2=false;
           if(arr[i-1]<=j)
           c2=prev[j-arr[i-1]];
           curr[j]=c1||c2;
       }
       prev=curr;
   }
   return prev[k];
}
