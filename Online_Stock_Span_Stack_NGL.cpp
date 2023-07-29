#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    vector<int> v;
    stack<pair<int,int>> s;
    for(int i=0;i<price.size();i++){
        if(s.size()==0){
            v.push_back(-1);
        }else if(s.size()>0 && s.top().first > price[i]){
            v.push_back(s.top().second);
        }else if(s.size()>0 && s.top().first<=price[i]){
            while(s.size()>0 && s.top().first<=price[i]){
                s.pop();
            }
            if(s.size()==0) v.push_back(-1);
            else v.push_back(s.top().second);
        }
        s.push({price[i],i});
    }
    
    for(int i=0;i<v.size();i++){
        v[i] = i - v[i];
    }
    return v;
}