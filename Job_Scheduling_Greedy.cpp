#include <bits/stdc++.h> 
bool comparator(vector<int> a,vector<int> b){
    return (a[1]>b[1]);
}
int jobScheduling(vector<vector<int>> &jobs)
{
   sort(jobs.begin(),jobs.end(),comparator);
   int maxd=jobs[0][0];
   for(int i=0;i<jobs.size();i++){
       if(jobs[i][0]>maxd){
           maxd=jobs[i][0];
       }
   }
   vector<int> slot(maxd+1,-1);
   int count=0,profit=0;

   for(int i=0;i<jobs.size();i++){
       for(int j=jobs[i][0];j>0;j--){
           if(slot[j]==-1){
               slot[j]=i;
                count++;
                profit+=jobs[i][1];
                break;
           }
       }
   }
   return profit;
}
