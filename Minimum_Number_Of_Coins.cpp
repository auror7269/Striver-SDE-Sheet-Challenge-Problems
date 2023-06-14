#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int count=0;
    
    vector<int> coins={1,2,5,10,20,50,100,500,1000};
    int n=coins.size();
    for(int i=n-1;i>=0;i--){
        while(amount>=coins[i]){
            amount-=coins[i];
            count++;
        }
    }
    return count;
}
