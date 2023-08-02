#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int,int>ans;
	vector<int>temp(n,0);
  
	for(int i=0;i<n;i++)
		temp[arr[i]-1]++;
  
	for(int i=0;i<n;i++)
	{
       if(temp[i]==0)ans.first=i+1;
       if (temp[i] == 2) {
         ans.second = i + 1;
       }
  }
	return ans;	
}
