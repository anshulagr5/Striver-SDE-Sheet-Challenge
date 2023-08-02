#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++)
    {
        if(st.size()==0||arr[i]>=arr[st.top()])st.push(i);
        else{
           while(st.size()!=0 && arr[i]<arr[st.top()])
           {
             ans[st.top()]=arr[i];
             st.pop();
           }
           st.push(i);
        }
        
    }
    return ans;
}
