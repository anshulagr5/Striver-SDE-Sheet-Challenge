#include <bits/stdc++.h> 
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n=nums.size();
    deque<int>window;
    vector<int>maxwindowk;

    for(int i=0;i<n;i++)
    {
        if(!window.empty() && window.front()==i-k)window.pop_front();

        while(!window.empty() && nums[i]>nums[window.back()])window.pop_back();
        window.push_back(i);

        if(i>=k-1)maxwindowk.push_back(nums[window.front()]);
    }
    return maxwindowk;
}
