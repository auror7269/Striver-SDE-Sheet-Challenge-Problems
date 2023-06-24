#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto i : arr){
        mp[i]++;
    }
    for(auto & i:mp){
        pq.push({i.second,i.first});
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<int> ans;
    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}