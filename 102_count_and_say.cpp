#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	string temp1="1";
	for(int i=1;i<n;i++)
	{
	  int j=1;
		int count=1;
		string temp2="";
		while(j<temp1.size())
		{
			if(temp1[j]==temp1[j-1])count++;
			else{
				char t='0'+count;
        temp2.push_back(t);
				temp2.push_back(temp1[j-1]);
			  count=1;
			}
			j++;
		}
		temp2.push_back('0'+count);
		temp2.push_back(temp1[j-1]);
		temp1=temp2;
	}
	return temp1;
}
