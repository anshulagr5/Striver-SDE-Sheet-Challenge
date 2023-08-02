#include<bits/stdc++.h>

int editDistance(string str1, string str2)
{
    int n=str1.size();
    int m=str2.size();
    vector<int>prev(m+1),curr(m+1);
    for(int i=0;i<=m;i++)prev[i]=i;
    for(int i=1;i<=n;i++)
    {
        curr[0]=i;
        for(int j=1;j<=m;j++)
        {
            int ans=0;
            if(str1[i-1]==str2[j-1]){
                ans=prev[j-1];
            }
            else{
                int s1=1+prev[j-1];
                int s2=1+prev[j];
                int s3=1+curr[j-1];
               ans=min(s1,min(s2,s3));
            }
          curr[j]=ans;
        }
        prev=curr;
    }
    return prev[m];

}
