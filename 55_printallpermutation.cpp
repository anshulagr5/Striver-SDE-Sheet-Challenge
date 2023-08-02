#include <bits/stdc++.h> 
using namespace std;

void helper(vector<string>&ans,string s,string temp)
{
    if(s.size()==0){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        char t=s[i];
        temp.push_back(t);
        s.erase(s.begin()+i);
        helper(ans,s,temp);
        temp.pop_back();
        s.insert(s.begin()+i,1,t);
    }
}

vector<string> findPermutations(string &s) {
    vector<string>ans;
    helper(ans,s,"");
    return ans;
}

