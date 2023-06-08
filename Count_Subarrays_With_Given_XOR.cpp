#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
   int xr=0;
   map<int,int> mp;
   mp[xr]++;
   int cnt=0;
   for(int i=0;i<arr.size();i++){
       xr=xr^arr[i];
       int a=xr^x;
       cnt+=mp[a];
       mp[xr]++;
   }
   return cnt;
}