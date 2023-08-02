#include<bits/stdc++.h>

void findLongestP(string s,int &start,int &psize,int l,int h)
{
    while(l>=0 && h<s.size()&& s[l]==s[h])
            {
                if(h-l+1>psize)
                {
                    start=l;
                    psize=h-l+1;
                }
                l--;
                h++;
            }
}


string longestPalinSubstring(string str)
{
    int start=0;
    int psize=1;
    int n=str.size();
     for(int i=0;i<n;i++)
            findLongestP(str,start,psize,i,i+1);
       
       for(int i=1;i<n;i++)
           findLongestP(str,start,psize,i-1,i+1);
       
     string res="";
       for(int i=start;i<start+psize;i++)
       {
            res+=str[i];
       }
       return res;
}
