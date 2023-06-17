#include <bits/stdc++.h> 
void solve(int ind, vector<int> arr,vector<vector<int>> &ans, 
vector<int> ds, int n,int k){
    if(n==0){
        if(k==0) ans.push_back(ds);

        return;
    }
    solve(ind+1,arr, ans, ds, n-1, k );
    ds.push_back(arr[ind]);
    solve(ind+1,arr, ans, ds, n-1, k-arr[ind]);
    return;
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
  
   vector<vector<int>> ans;
   vector<int> ds;
   solve(0,arr,ans,ds,n,k);
   return ans;
}