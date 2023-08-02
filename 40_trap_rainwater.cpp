#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long ans=0;
    long maxelevation=0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxelevation){
            maxelevation=arr[i];
            maxi=i; // find the maximum elevation point
        }
    }
    int low=0;
    int high=n-1;
    long maxl=arr[0];//left side max from current low index
    long maxh=arr[n-1];//right side max from current high index
    while(low<maxi || high >maxi)
    {
        maxl=max(arr[low],maxl);
        ans+=(maxl-arr[low]);
        maxh=max(arr[high],maxh);
        ans+=(maxh-arr[high]);
        if(low<maxi)low++;
        if(high>maxi)high--;
    }
    return ans;
}
