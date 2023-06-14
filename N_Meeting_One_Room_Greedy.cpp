#include <bits/stdc++.h> 
struct meeting{
    int start;
    int end;
    int pos;
};
bool comparator(struct meeting m1, meeting m2){
    if(m1.end<m2.end) return true;
    else if(m1.end>m2.end) return false;
    else if(m1.pos<m2.pos) return true;

    return false;

    

}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n=start.size();
   struct meeting m[n];
   for(int i=0;i<n;i++){
       m[i].start=start[i]; m[i].end=end[i]; m[i].pos=i+1;
   }
   sort(m,m+n, comparator);

   vector<int> ans;
   int last=m[0].end;
   ans.push_back(m[0].pos);
   for(int i=1;i<n;i++){
       if(m[i].start > last){
           last=m[i].end;
           ans.push_back(m[i].pos);
       }
   }
   return ans;

}