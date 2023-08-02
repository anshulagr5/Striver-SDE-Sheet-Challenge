#include <bits/stdc++.h> 

bool static isPossible(long long mid, int n,vector<int>time)
{
    int count=1; long long sum=0;
    for(auto it:time)
    {
        if(it>mid)return false;
        if(sum+it>mid){
            count++;
            sum=it;
        }
        else sum+=it;
        if(count>n)return false;
    }
      if(count>n)return false;
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
     long long low=time[0];
     long long high=0;
     for(auto it:time){low=max(low,(long long)it);high+=it;}
     long long mid;
     long long res=-1;
     while(low<=high)
     {
         mid=low+(high-low)/2;
         if(isPossible(mid,n,time)){
             res=mid;
             high=mid-1;
         }
         else low=mid+1;
     }
     return res;
}
