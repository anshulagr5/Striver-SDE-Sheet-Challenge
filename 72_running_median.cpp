#include<bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n)
{
    vector<int>temp;
    for(int i=0;i<n;i++)
    {
        int element=arr[i];
        if(temp.size()==0)temp.push_back(element);
        else{
            int low=0;
            int high=temp.size()-1;
            int mid;
            while(low<=high)
            {
                mid=low+(high-low)/2;
                if(temp[mid]>element)high=mid-1;
                else low=mid+1;
            }
            temp.insert(temp.begin()+low,element);
        }
        int ts=temp.size();

        if(ts%2==1)
        {
            int oddmed=temp[ts/2];
            cout<<oddmed<<" ";
        }
        else{
            int evenmed=(temp[ts/2]+temp[(ts/2)-1])/2;
            cout<<evenmed<<" ";
        }
    }
}
