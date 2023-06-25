#include <bits/stdc++.h>

vector<vector<int>> pwset(vector<int>v)

{
int n=v.size();
vector<vector<int>>ans;
for(int num=0;num<(1<<n);num++){
vector<int>temp;
for(int i=0;i<n;i++){
if(num&(1<<i)){
temp.push_back(v[i]);
}
}
if(temp.size()>0){
ans.push_back(temp);
}
}
sort(ans.begin(),ans.end());
return ans;
}

