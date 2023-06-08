#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   
   int n=arr.size();
   vector<vector<int> > ans;
   for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
         if(arr[i]+arr[j]==s){
            
            vector<int> temp={arr[i],arr[j]};
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
         }
      }
   }
   sort(ans.begin(),ans.end());
   return ans;
}