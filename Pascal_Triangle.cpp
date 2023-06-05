#include <bits/stdc++.h>
vector<long long int> getRow(int row){
  long long int ans=1;
  vector<long long int> ans1;
  ans1.push_back(1);
  for(int i=1;i<row;i++){
    ans=ans*(row-i);
    ans=ans/i;
    ans1.push_back(ans);
  }
  return ans1;
}
vector<vector<long long int>> printPascal(int n) 
{
  
  vector<vector<long long int>> res;
  for(int i=1;i<=n;i++){
    res.push_back(getRow(i));
  }
  return res;
}
