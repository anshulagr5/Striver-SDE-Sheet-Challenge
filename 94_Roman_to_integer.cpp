#include<bits/stdc++.h>

int romanToInt(string s) {
      unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int sum=mp[s.at(s.size()-1)];
        for(int i=s.size()-1;i>0;i--)
        {
           if(mp[s.at(i)]<=mp[s.at(i-1)])
           {
               sum+=mp[s.at(i-1)];
           }
           else
           {
               sum-=mp[s.at(i-1)];
           }
        }
        return sum;
}
