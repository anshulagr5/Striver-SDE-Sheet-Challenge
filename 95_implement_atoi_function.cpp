#include <bits/stdc++.h> 
int atoi(string s) {
    int n=s.size();
    int sum=0;
    int minus=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='-'){
            if(minus==1)minus=-1;
            else minus=1;
        }
        else if(s[i]>='0'&&s[i]<='9')sum=sum*10+(s[i]-'0');
    }
    return (minus)*sum;
}
