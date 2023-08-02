#include <bits/stdc++.h> 
using namespace std;

void sortStack(stack<int> &stk)
{
	if(stk.size()==0)return;

	stack<int>st1;
	int x=stk.top();
	stk.pop();
		
	sortStack(stk);

	while(stk.size()!=0 && stk.top()>x)
	{
		st1.push(stk.top());
		stk.pop();
	}
	
	stk.push(x);
	
	while(st1.size()!=0){
		stk.push(st1.top());
		st1.pop();
	}

}
