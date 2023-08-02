#include <bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size();
    int xorsum=0;
    unordered_map<int,int>umap;
    
    umap[xorsum]++;
    int count=0;
    for(int i=0;i<n;i++)
    {
        xorsum=xorsum^arr[i];
        count+=umap[xorsum^x];
        umap[xorsum]++;
    }
    return count;
}
