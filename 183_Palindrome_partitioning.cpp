#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i ,int j,string temp)
{
    while(i<j)
    {
        if(temp[i]!=temp[j])return false;
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string str)
{
    int n=str.size();
    vector<int>dp(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        int ans=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(isPalindrome(i,j,str))
            {
                ans=min(ans,1+dp[j+1]);
            }
        }
        dp[i]=ans;
    }
    return dp[0]-1;
}
