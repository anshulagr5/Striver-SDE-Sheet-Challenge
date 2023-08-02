#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
   priority_queue<int,vector<int>,greater<int>>pq;
   int i=0;
   while(K--)pq.push(arr[i++]);
   
   for(;i<size;i++){
      pq.push(arr[i]);
      pq.pop();
   }
   return pq.top();
}
