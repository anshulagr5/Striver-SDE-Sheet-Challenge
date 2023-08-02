#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int arr[]={1,2,5,10,20,50,100,500,1000};
    int i=8;
    int count=0;
    while(i>=0 && amount>0)
    {
        if(amount>=arr[i]){
            count+= amount/arr[i];
            amount=amount%arr[i];
        }
        i--;
    }
    return count;
}
