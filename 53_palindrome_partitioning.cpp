#include <bits/stdc++.h> 
using namespace std;

bool static Ispalindrome(string s,int low,int high)
{
    while(low<high)
    {
        if(s[low]!=s[high])return false;
        low++;
        high--;
    }
    return true;
}
void helper(vector<vector<string>>&ans,vector<string>temp,string s,int index)
{
    if(index==s.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=index;i<s.size();i++)
    {
        bool check=Ispalindrome(s,index,i);
        if(check){
            string st=s.substr(index,i-index+1);
            temp.push_back(st);
            helper(ans,temp,s,i+1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>>ans;
    vector<string>temp;
    helper(ans,temp,s,0);
    return ans;
}


