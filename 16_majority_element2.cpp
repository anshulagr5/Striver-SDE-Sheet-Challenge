#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{
   int n=arr.size();
   int check_occur=n/3;
   vector<int>ans;

	unordered_map<int,int>umap;
	for(int i=0;i<n;i++)umap[arr[i]]++;

	for(auto it:umap)if(it.second>check_occur)ans.push_back(it.first);
	
	return ans;
}
