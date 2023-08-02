#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
     vector<int>medians;
     priority_queue<int>maxh;
     priority_queue<int,vector<int>,greater<int>>minh;

     for(int i=0;i<n;i++)
     {
        maxh.push(arr[i]);
        minh.push(maxh.top());
        maxh.pop();

        if(maxh.size()<minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }

        int median;
        if(maxh.size()>minh.size()){
            median=maxh.top();
        }
        else{
            median=(maxh.top()+minh.top())/2;
        }
        medians.push_back(median);
     }
     return medians;
}
