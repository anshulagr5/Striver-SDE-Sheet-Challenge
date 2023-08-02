#include<bits/stdc++.h>

vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
    int n=s.size();
   vector<vector<string>>dp(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            string temp=s.substr(j,i-j+1);
            if(find(dict.begin(),dict.end(),temp)!=dict.end())
            {
                if(j>0){
                    for(auto it:dp[j-1])
                        dp[i].push_back(it+" "+temp);
                }
                else
                    dp[i].push_back(temp);
                
            }
        }
    }
    return dp[n-1];
}

