#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	int ans;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		if(arr[i]==arr[i+1]){
			ans=arr[i];
			break;
		}
	}
	return ans;
}
