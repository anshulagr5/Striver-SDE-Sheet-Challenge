#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n) {
	int check_occur=n/2;
  
	unordered_map<int,int>umap;
	for(int i=0;i<n;i++)umap[arr[i]]++;

	for(auto it:umap)if(it.second>check_occur)return it.first;
	
	return -1;
}
