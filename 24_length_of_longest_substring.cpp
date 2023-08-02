#include <bits/stdc++.h> 
using namespace std;
int uniqueSubstrings(string input)
{
   int n=input.size();
    vector<int>umap(256,-1);
    int ans=0;
    int lower_index=0;

    for(int i=0;i<n;i++)
    {
       if(umap[input[i]]!=-1)
       lower_index=max(lower_index,umap[input[i]]+1);

       ans=max(i-lower_index+1,ans);
       umap[input[i]]=i;
       
    }
    return ans;
    
}
