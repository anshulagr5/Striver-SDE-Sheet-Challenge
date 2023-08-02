#include <bits/stdc++.h> 

vector<vector<int>>findtarget(vector<int>arr,int target,int low,int element)
{
	vector<vector<int>>ans;
	int high=arr.size()-1;
	while(low<high)
	{
          if (arr[high] + arr[low] == target) {
	    vector<int>temp;
	
	    temp.push_back(element);
            temp.push_back(l);
            temp.push_back(h);
	    ans.push_back(temp);
		  
            while(low<high && arr[low+1]==arr[low])low++;
	    while(low<high && arr[high-1]==arr[high])high--;
		  
	    low++;
	    high--;
          } 
         else if (arr[high] + arr[low] > target)
            high--;
          else
            low++;
	}
	return ans;
}
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	 vector<vector<int>>ans;
         sort(arr.begin(),arr.end());
	 for(int i=0;i<n-2;i++)
	 {
		 if(i>0 && arr[i]==arr[i-1])continue;
		 
		 int target=K-arr[i];
		 vector<vector<int>>temp=findtarget(arr,target,i+1,arr[i]);
		 for(auto it:temp)
			 ans.push_back(it);

	 }
	 return ans;
}
