#include<bits/stdc++.h>
using namespace std;

vector<int> stringMatch(string text, string pattern) {
	int d=256;
	int lprime=2147483647;
	int n=text.size();
	int m=pattern.size();
	vector<int>ans;
	int h=1;
	int p=0;
	int t=0;

	for(int i=0;i<m-1;i++){
		h=(h*d)%lprime;
	}
	for(int i=0;i<m;i++){
       t=(d*t+ text[i])%lprime;
	     p=(d*p+pattern[i])%lprime;
	}
	
	for(int i=0;i<=n-m;i++){
		if(p==t){
			int j;
			for(j=0;j<m;j++){
				if(text[i+j]!=pattern[j])break;
			}
			if(j==m)ans.push_back(i+1);
		}
		if(i<n-m){
			t=(d*(t-text[i]*h) + text[i+m])%lprime;
			if(t<0)
			 t=t+lprime;
		}
	}
	return ans;
}
