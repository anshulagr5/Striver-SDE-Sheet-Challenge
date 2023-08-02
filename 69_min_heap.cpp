#include <bits/stdc++.h> 
using namespace std;

vector<int> minHeap(int n, vector<vector<int>>& q) {
     vector<int>arr;
     vector<int>ans;
     for(int i=0;i<n;i++)
     {
       
        if(q[i][0]==1 && arr.size()==0)continue;
        else if(q[i][0]==1 && arr.size()!=0){
            ans.push_back(arr[arr.size()-1]);
            arr.pop_back();
        }
        else if(q[i][0]==0) {
            if(arr.size()!=0){
                int temp=arr[arr.size()-1];
                if(q[i][1]<=temp)arr.push_back(q[i][1]);
                else
                 {
                    for(int j=0;j<arr.size();j++)
                    {
                        if(q[i][1]>arr[j])
                        {
                            arr.insert(arr.begin()+j,q[i][1]);
                            break;
                        }
                    }
                 }
              
            }
            else arr.push_back(q[i][1]);
        }
        
     }
     return ans;
}
