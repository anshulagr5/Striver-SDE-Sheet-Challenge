#include<bits/stdc++.h>
using namespace std;

int helper(string s,string t,int i,int j,vector<vector<int>>&dp)
{
	if(i<0 || j<0)return 0;
	int ans=0;
	if(dp[i][j]!=-1)return dp[i][j];
	if(s.at(i)==t.at(j)){
		ans=1+helper(s,t,i-1,j-1,dp);
	}
	else{
		ans=max(helper(s,t,i-1,j,dp),helper(s,t,i,j-1,dp));
	}
	return dp[i][j]=ans;

}
int lcs(string s, string t)
{
	int m=s.size();
	int n=t.size();
	vector<int>curr(n+1),prev(n+1,0);
	for(int i=1;i<=m;i++)
	{
		curr[0]=0;
		for(int j=1;j<=n;j++)
		{
			if(s.at(i-1)==t.at(j-1)){
				curr[j]=1+prev[j-1];
			}
			else{
				curr[j]=max(prev[j],curr[j-1]);
			}
		}
		prev=curr;

	}
	return prev[n];
}
