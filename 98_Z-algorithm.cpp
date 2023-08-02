#include<bits/stdc++.h>
using namespace std;

int zAlgorithm(string text, string pattern, int n, int m)
{
	string st=pattern +'#'+text;
    int k=st.size();
    int l=0;
    int r=0;
    vector<int>zarr(k,0);
    int ans=0;
    for(int i=1;i<k;i++)
    {
        if(i<r)
          zarr[i]=min(r-i,zarr[i-l]);
        
        while(i+zarr[i]<k && st[zarr[i]]==st[i+zarr[i]])
        zarr[i]++;

        if(i+zarr[i]>r){
            l=i;
            r=i+zarr[i];
        }
        if(i>=m+1 && zarr[i]==m)ans++;
    }
    return ans;
}
