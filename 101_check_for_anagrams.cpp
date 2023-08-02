#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    vector<int>arr(256,0);
    if(str1.size()!=str2.size())return false;
    int n=str1.size();

    for(int i=0;i<n;i++)
    {
        arr[str1[i]]++;
        arr[str2[i]]--;
    }
    for(int i=0;i<256;i++)
    if(arr[i]!=0)return false;
    return true;
}
