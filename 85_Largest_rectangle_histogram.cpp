 #include<bits/stdc++.h>
 using namespace std;
 
 vector<int> nextsmaller(vector<int>h){
   int n=h.size();
    stack<int>st;
    vector<int>ans(n,n);
    st.push(0);
    int i=1;
    while(i<n){
    
        while(st.size()!=0 &&h[st.top()]>h[i]){
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
    st.push(n-1);
    int i=n-2;
    while(i>=0){
    
        while(st.size()!=0 &&h[st.top()]>h[i]){
          ans[st.top()]=i;
          st.pop();
        }
        st.push(i);
        i--; 
      
    }
   
    return ans;
 }
 int largestRectangle(vector < int > & heights) {
    int n=heights.size();
    vector<int> nextsmallgroup=nextsmaller(heights);
    vector<int> prevsmallgroup=prevsmaller(heights);
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
      int ls,rs;
      rs=nextsmallgroup[i];
      ls=prevsmallgroup[i];
      int area=(rs-ls-1)*heights[i];
      ans=max(ans,area);
    }
    return ans;
 }
