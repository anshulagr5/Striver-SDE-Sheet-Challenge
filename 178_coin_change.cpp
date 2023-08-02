#include<bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
   
    vector<long>prev(value+1,0),curr(value+1);
    for(int i=1;i<=n;i++){
        curr[0]=1;
        for(int j=1;j<=value;j++)
        {
            long c1=prev[j];
            long c2=0;
            if(denominations[i-1]<=j)
            c2=curr[j-denominations[i-1]];
            curr[j]=c1+c2;
        }
        prev=curr;
    }
    return prev[value];

}
