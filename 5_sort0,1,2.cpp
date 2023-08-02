#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   
        vector<int>colors(3,0);
        for(int i=0;i<n;i++)
        {
            colors[arr[i]]++;
        }
        int curr_ind=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<colors[i];j++)
            {
                arr[curr_ind]=i;
                curr_ind++;
            }
         }
    
}
