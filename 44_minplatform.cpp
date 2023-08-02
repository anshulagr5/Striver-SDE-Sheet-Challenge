#include<bits/stdc++.h>
using namespace std;
int calculateMinPatforms(int at[], int dt[], int n) {

    sort(at,at+n);
    sort(dt,dt+n);

    int count=0;
    int ans=0;
    int arrival=0;
    int departure=0;
    while(arrival<n && departure<n)
    {
        if(at[arrival]<=dt[departure])
        {
             arrival++;
             count++;
        }
        else{
            departure++;
            count--;
        }
        ans=max(count,ans);
    }
    return ans;
}
