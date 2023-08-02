void helper(vector<vector<int>>&ans,vector<int>&temp,vector<int>arr,int index, int sum)
{
	if(sum==0){
      ans.push_back(temp);
			return;
	}
	 
	 for(int i=index;i<arr.size();i++)
	 {
		 if(i>index && arr[i]==arr[i-1])continue;
		 if(arr[i]>sum)break;
		 temp.push_back(arr[i]);
		 helper(ans,temp,arr,i+1,sum-arr[i]);
		 temp.pop_back();
	 }
	
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
    vector<vector<int>>ans;
	vector<int>temp;
	sort(arr.begin(),arr.end());
    helper(ans,temp,arr,0,target);
    return ans;
}
