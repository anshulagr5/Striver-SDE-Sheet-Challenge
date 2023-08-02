void helper(vector<vector<int>>&ans,vector<int>&arr,vector<int>&temp,int index,int sum)
{
    
    if(index==arr.size())
    {
        if(sum==0)ans.push_back(temp);
        return;
    }
    temp.push_back(arr[index]);
    helper(ans,arr,temp,index+1,sum-arr[index]);
    temp.pop_back();
    helper(ans,arr,temp,index+1,sum);
    return;
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>>ans;
    vector<int>temp;
    helper(ans,arr,temp,0,k);
    return ans;
}
