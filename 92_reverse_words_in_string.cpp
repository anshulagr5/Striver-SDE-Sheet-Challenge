#include<bits/stdc++.h>
string reverseString(string &str){
	stack<string>st;
	int n=str.size();
	for(int i=0;i<n;i++)
	{
		if(str[i]==' ')continue;
		int j=i;
		string temp="";
		while(j<n && str[j]!=' '){temp+=str[j];j++;}
		i=j-1;
		st.push(temp);

	}
	string ans="";
	while(!st.empty())
	{
		ans+=st.top();
		st.pop();
		if(!st.empty())ans+=' ';
	}
	return ans;
}
