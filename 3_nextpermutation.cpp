#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    vector<int>ans=permutation;
    int left=0,right=0;

     for( left=n-2;left>=0;left--)
     {
         if(ans[left]<ans[left+1])break;
     }
    if(left<0)
        reverse(ans.begin(),ans.end());
    else
    {
        for(right=n-1;right>left;right--)
        {
            if(ans[left]<ans[right])break;
        }
        swap(ans[left],ans[right]);
        reverse(ans.begin()+left+1,ans.end());
        
    }
    return ans;
}
