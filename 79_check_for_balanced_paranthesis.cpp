#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    int i=0;
    int n=expression.size();
    stack<char>st;
    while(i<n)
    {
        char temp=expression[i];
        if(temp=='(' || temp=='{'||temp=='[')st.push(temp);
        else{
            if(st.empty())return false;
            else{
                  if((st.top()=='(' && temp==')')||(st.top()=='{' && temp=='}')
                ||(st.top()=='[' && temp==']'))st.pop();
                 else return false;
            }
          
        }
        i++;
    }
    if(st.size()==0)return true;
    return false;
}
