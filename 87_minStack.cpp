#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	vector<int>st;
	vector<int>minindex;
  int stTop;
	int minTop;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			stTop=-1;
			minTop=-1;
		};
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			st.push_back(num);
			stTop+=1;
			if((minTop==-1)||(st[minindex[minTop]]>num))
			 {
				 minindex.push_back(stTop);
				 minTop+=1;
			 }  
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
		   if(stTop==-1)return -1;
		   if(minindex[minTop]==stTop){minindex.pop_back();minTop-=1;}
		   int x= st[stTop];
		   st.pop_back();
		   stTop-=1;
		   return x;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(stTop==-1)return -1;
			return st[stTop];
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(minTop==-1)return -1;
			return st[minindex[minTop]];
		}
};
