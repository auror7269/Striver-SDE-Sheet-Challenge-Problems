#include <bits/stdc++.h> 
struct activity{
    int start;
    int end;
    
};
bool comparator(struct activity a, activity b){
    if(a.end<b.end) return true;
    else if(a.end>b.end) return false;
    

    return false;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
   
    int n=start.size();
     activity a[n+1];
    for(int i=0;i<start.size();i++){
        a[i].start=start[i]; a[i].end=finish[i]; 
    }
    sort(a,a+n, comparator);
    int count=1;
    int last=a[0].end;
    for(int i=1;i<n;i++){
        if(a[i].start>=last){
            last=a[i].end;
            count++;
        }
    }
    return count;
}