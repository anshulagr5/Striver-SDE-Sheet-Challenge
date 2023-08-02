#include<bits/stdc++.h>
using namespace std;

int getMedian(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    vector<int>temp;
    temp=matrix[0];
    int m=temp.size();
    for(int i=1;i<n;i++)
    {
         int low=0;
         int high=temp.size()-1;
        for(int j=0;j<m;j++)
        {
            int find=matrix[i][j];
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(temp[mid]>find)high=mid-1;
                else low=mid+1;
            }
            if(low>=0 && low<=temp.size())temp.insert(temp.begin()+low,find);
            low=high;
            high=temp.size()-1;
        }
    }
    int tempsize=temp.size();
    return temp[(tempsize-1)/2];

}
