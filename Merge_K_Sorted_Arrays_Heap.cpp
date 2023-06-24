#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater
    <pair<int,pair<int,int>>>> pq;
    vector<int> v;
    for(int i=0;i<k;i++){
      pq.push({
          kArrays[i][0],{i,0}
      });
    }
    while(pq.size()>0){
        auto temp=pq.top();
        pq.pop();
        int value=temp.first;
        int li=temp.second.first;
        int di=temp.second.second;
        v.push_back(value);
        if(di+1<kArrays[li].size()){
            pq.push({kArrays[li][di+1],{li,di+1}});
        }
    }
    return v;
}
