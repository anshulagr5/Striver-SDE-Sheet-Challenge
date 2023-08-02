#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	
	// DP space optimisation solution T.C= O(m*n) ans S.c=O(n)
	
	vector<int>temp(n),curr(n);
	curr[0]=1;
	for(int i=1;i<n;i++ )curr[i]=1;
	for(int i=1;i<m;i++)
	{
        for(int j=0;j<n;j++)
		{
			if(j==0)temp[0]=1;
			else temp[j]=temp[j-1]+curr[j];
		}
		curr=temp;
	}
	return curr[n-1];
}
