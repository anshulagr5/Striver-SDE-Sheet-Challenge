#include<bits/stdc++.h>

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<int>dp(n);
	dp[0]=rack[0];
    int ans=rack[0];
    
	for(int i=1;i<n;i++)
	{
		int maxi=INT_MIN;
		for(int j=0;j<i;j++)
		{
           if(rack[i]>rack[j]){
			   maxi=max(maxi,dp[j]+rack[i]);
		   }
		}
		if(maxi==INT_MIN){
           dp[i]=rack[i];
		}
		else{
			dp[i]=maxi;
		}
		ans=max(dp[i],ans);
	}
	return ans;
}
