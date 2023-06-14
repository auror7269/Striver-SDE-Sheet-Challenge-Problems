#include <bits/stdc++.h>
void solve(int ind, int sum, vector<int> &num, vector<int> &ans){
    if(ind==num.size()) {
        ans.push_back(sum);
        return;
        }

    solve(ind+1, sum+num[ind], num, ans);
    solve(ind+1, sum, num , ans);
    return;
} 
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    solve(0,0,num,ans);
    sort(ans.begin(),ans.end());
    return ans;
 }