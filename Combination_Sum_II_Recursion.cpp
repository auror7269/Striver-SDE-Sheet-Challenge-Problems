#include <bits/stdc++.h> 
void solve(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> ds,
int target){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        ds.push_back(arr[i]);
        solve(i+1, arr, ans, ds, target-arr[i]);
        ds.pop_back();
    }
    return;
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{   sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
    vector<int> ds;
    solve(0, arr, ans, ds, target);
    return ans;
}
