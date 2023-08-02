#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m) {
    int ans=1;
	while(n)
	{
           if(n&1)
           {
              ans=(ans*1LL*x)%m;
	   }
	   x=(x*1LL*x)%m;
	   n>>=1;
	}
	return ans;
}
