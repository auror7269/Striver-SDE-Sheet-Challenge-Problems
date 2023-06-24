#include <bits/stdc++.h> 
#include <set>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(),a.end());
	sort(b.begin(), b.end());

	priority_queue<pair<int,pair<int,int>>> max;
	max.push({a[n-1]+b[n-1],{n-1,n-1}});
	set<pair<int,int>> st;
	st.insert({n-1,n-1});
	vector<int> result;
	while(k>0){
		pair<int, pair<int,int>> temp=max.top();
		max.pop();

		int sum=temp.first;
		int x=temp.second.first;
		int y=temp.second.second;

		result.push_back(sum);

		if(st.find({x-1,y})==st.end()){
			max.push({a[x-1]+b[y],{x-1,y}});
			st.insert({x-1,y});
		}
		if(st.find({x,y-1})==st.end()){
			max.push({a[x]+b[y-1],{x,y-1}});
			st.insert({x,y-1});
		}
		k-=1;
	}
	return result;
}