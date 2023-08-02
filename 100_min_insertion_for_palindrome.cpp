#include<bits/stdc++.h>
using namespace std;

int minCharsforPalindrome(string str) {
	int i=0;
	int j=str.size()-1;
	int res=0;
	int trim=j;
  
// calculate the maximum possible palindrome from starting position is of size(s) then subtract it from total size(t) -> ans=t-s;
  
	while(i<j)
	{
		if(str[i]==str[j])
		{
			i++;
			j--;
		}
		else{
			res++;
			i=0;
			j=--trim;
		}
	}
	return res;
}
