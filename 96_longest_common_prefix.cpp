#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &arr, int n)
{
    int low=1;
    int high=1000; //it is given that size of string lies between 1 to 1000;
    while(low<=high)
    {
        int mid=low +(high-low)/2;
        string check;
        if(mid>arr[0].size()){high=mid-1;continue;} //size of common prefix must be minimum than current size so high=mid-1;
        else if(mid==arr[0].size())check=arr[0];
        else  check=arr[0].substr(0,mid);
    
        int i=1;
        for(i=1;i<n;i++)                 //check for other string whether it satisfy this condition or not
        {
           string temp;
           if(mid>arr[i].size())break;
           else if(mid==arr[i].size())temp=arr[i];
           else temp= arr[i].substr(0,mid);
           if(temp!=check)break;
        }
        if(i==n)low=mid+1; //if satisfy then check for higher size
        else high=mid-1;  // if not satisfy then check for lesser size
        
    }
    if(high==0)return ""; 
    return arr[0].substr(0,high);
}


