#include<bits/stdc++.h>
using namespace std;


string kthPermutation(int n, int k) {
   int ft=1;
   vector<int>nums;
   for(int i=1;i<n;i++)
   {
       ft=ft*i;
       nums.push_back(i);
   }
   nums.push_back(n);
   k=k-1;
   string ans="";
   while(1)
   {
       ans+=to_string(nums[k/ft]);
       nums.erase(nums.begin()+k/ft);

       if(nums.size()==0)break;
       k=k%ft;
       ft=ft/nums.size();
   }
   return ans;
}
