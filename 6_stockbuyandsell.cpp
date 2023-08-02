#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n=prices.size();
    int ans=0;
    int minbuy=prices[0];
    for(int i=0;i<n;i++)
    {
        //sell at everyday and compare current profit with previous profit
        if(prices[i]-minbuy>ans)ans=prices[i]-minbuy;

        //compare current price everyday with previous minimum buying price and store minimum buying price
        minbuy=min(minbuy,prices[i]);
    }
    return ans;
}
