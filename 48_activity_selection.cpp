#include<bits/stdc++.h>
using namespace std;

bool static compare(vector<int>&a,vector<int>&b)
{
    if(a[1]!=b[1])
      return a[1]<b[1];
    return a[0]<b[0];
}


int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n=start.size();
    vector<vector<int>>store;
    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        temp.push_back(start[i]);
        temp.push_back(finish[i]);
        store.push_back(temp);
    }
    sort(store.begin(),store.end(),compare);
    int lim=store[0][1];
    int count=1;
    for(int i=1;i<n;i++)
    {
      if (store[i][0] >= lim) {
        count++;
        lim = store[i][1];
      }
    }
    return count;
}
