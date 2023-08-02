#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	vector<int>temp(n,0);
	for(int i=0;i<n;i++)
	{
    //store the non-repeated element and check the element which repeats.
		if(temp[arr[i]]==0)temp[arr[i]]++;
		else return arr[i];
	}
	return -1;
}
