#include <bits/stdc++.h> 

vector<int>lps(string p)
{
    int n=p.size();
    vector<int>temp(n,0);
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(p[i]==p[j])
        {
            temp[i]=j+1;
            j++;
        }
        else{
            while(j>0)
            {
                j=temp[j-1];
                if(p[j]==p[i])
                {
                    temp[i]=j+1;
                    j++;
                    break;
                }
            }
        }
    }
    return temp;
}
bool findPattern(string p, string s)
{
   int n=s.size();
   int m=p.size();

   vector<int>LPS=lps(p);
   int i=0;
   int j=0;
   while(i<n)
   {
      if(s[i]==p[j]){
          if(j==m-1)return true;
          j++;
          i++;
      }
      else{
          if(j>0)
           j=LPS[j-1];
          else
           i++;
      }
   }
   return false;
}
