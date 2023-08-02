#include<bits/stdc++.h>

int cutRod(vector<int> &price, int n)
{
	vector<int>prev(n+1,0),curr(n+1);
	for(int i=1;i<=n;i++)
	{
		curr[0]=0;
		for(int cut=1;cut<=n;cut++)
		{
           int c1=prev[cut];
		   int c2=0;
		   if(cut>=i)
		   c2=price[i-1]+curr[cut-i];
		   curr[cut]=max(c1,c2);
		}
		prev=curr;
	}
	return prev[n];
}
