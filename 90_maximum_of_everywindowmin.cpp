#include <bits/stdc++.h> 

vector<int> nextsmaller(vector<int>h){
   int n=h.size();
    stack<int>st;
    vector<int>ans(n,n);
    int i=0;
    while(i<n){
    
        while(!st.empty() &&h[st.top()]>h[i]){
          ans[st.top()]=i;
          st.pop();
        }
        st.push(i);
        i++; 
    }
    
    return ans;
 }
 vector<int> prevsmaller(vector<int>h){
       int n=h.size();
    stack<int>st;
    vector<int>ans(n,-1);
    int i=n-1;
    while(i>=0){
    
        while(!st.empty() &&h[st.top()]>h[i]){
          ans[st.top()]=i;
          st.pop();
        }
        st.push(i);
        i--; 
      
    }
    return ans;
 }
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int>ans(n,INT_MIN);
    vector<int>prev=prevsmaller(a);
    vector<int>next=nextsmaller(a);
    for(int i=0;i<n;i++){
        int length=next[i]-prev[i]-1;
        ans[length-1]=max(ans[length-1],a[i]);
    }
    for(int i=n-2;i>=0;i--)ans[i]=max(ans[i],ans[i+1]);
    return ans;
}

