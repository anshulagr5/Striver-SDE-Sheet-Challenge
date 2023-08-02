#include <bits/stdc++.h> 
using namespace std;


vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	
  priority_queue<int> pq;
	 for(int i=n-1;i>=0;i--)
	 {
		 for(int j=n-1;j>=0;j--)
		 {
			 int sum=a[i]+b[j];
             pq.push(sum);
		 }
	 }
	 vector<int>ans;
	 while(k--)
	 {
	    ans.push_back(pq.top());
		pq.pop();
	 }
	 return ans;
	 

}
