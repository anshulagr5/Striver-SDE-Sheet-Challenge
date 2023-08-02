#include<bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m) {
  int low=1;
  int high=m;
  int mid;
  while(low<=high)
  {
     mid=low + (high-low)/2;
     if(pow(mid,n)==m)return mid;
     if(pow(mid,n)>m)high=mid-1;
     else low=mid+1;
  }

  return -1;
}
