#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    int n=price.size();
  
    stack<int>st;
    vector<int>ans(n,0);
  
    for(int i=1;i<=n;i++)ans[i-1]=i; // it store maximum possible answer at every ith day
  
    int i=n-1;
    while(i>=0){
        while(!st.empty()&& price[i]>price[st.top()])
        {
            ans[st.top()]=st.top()-i;// update if previous greater value exist
            st.pop();
        }
        st.push(i);
        i--;
        
    }
    return ans;
}
