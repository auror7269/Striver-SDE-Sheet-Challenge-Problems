#include <bits/stdc++.h> 
bool comp(pair<int,int>a,pair<int,int>b)
{
    double r1=(double)a.second/a.first;
    double r2=(double)b.second/b.first;
    return r1>r2;
}
double maximumValue (vector<pair<int,int>>& items, int n, int w)
{
         sort(items.begin(),items.end(),comp);

    double final_val=0.0;
    int curweight=0;

    for(int i=0;i<items.size();i++){
        if(curweight + items[i].first<=w){
            curweight+=items[i].first;
            final_val+=items[i].second;
        }else{
            int remain=w-curweight;
            final_val+=((double)items[i].second/(double)items[i].first)*(double) remain;
            break;
        }
    }
    return final_val;
}