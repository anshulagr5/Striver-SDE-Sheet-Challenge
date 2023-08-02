#include<bits/stdc++.h>
using namespace std;

bool static isPossible(int limit ,int k,vector<int>stalls)
{
    int n=stalls.size();
    int cowreq=1; int prevcow=stalls[0];
    for(int i=1;i<n;i++)
    {
        if(stalls[i]-prevcow>=limit)
        {
           cowreq++;
           prevcow=stalls[i];
        }
    }
    if(cowreq>=k)return true;;
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int low=1;
    int high=stalls[n-1]-stalls[0];

    int mid;
    while(low<=high)
    {
        mid=low + (high-low)/2;
        if(isPossible(mid,k,stalls))
            low=mid+1;
            
        else high=mid-1;
    }
    return high;
}
