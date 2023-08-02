#include <bits/stdc++.h> 
using namespace std;

void helper(vector<string>&ans,string store,string s,vector<string>dict,int index)
{
   int n=s.size();
   if(index==n){
       store.pop_back();
       ans.push_back(store);
   }
   for(int i=index;i<n;i++)
   {
      string temp=s.substr(index,i-index+1);
      if(find(dict.begin(),dict.end(),temp)!=dict.end())
         helper(ans,store+temp+" ",s,dict,i+1);  
   }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
   vector<string>ans;
   helper(ans,"",s,dictionary,0);
   return ans;
}
