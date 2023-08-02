#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& arr)
{
	int n=arr.size();
	int low=0;
	int high=n-1;
  int mid;
	while(low<=high)
	{
		 mid=low+(high-low)/2;
		 if(mid+1<n && arr[mid]==arr[mid+1] && (high-mid+1)%2==1)low=mid+2;
		 else if(mid+1<n && arr[mid]==arr[mid+1] && (mid-low+2)%2==1)high=mid-1;
		 else if(mid-1>=0 && arr[mid]==arr[mid-1] && (mid-low+1)%2==1)high=mid-2;
		 else if(mid-1>=0 && arr[mid]==arr[mid-1] && (high-mid)%2==1)low=mid+1;
		 else return arr[mid];
	}
	return -1;
}
