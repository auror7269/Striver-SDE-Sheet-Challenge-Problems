#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	for(int i=0;i<n-2;i++){
		if(i==0 || (i>0 && arr[i]!=arr[i-1])){
		int j=i+1;
		int k=n-1;
		
		while(j<k){
			if(arr[i]+arr[j]+arr[k]==K){
				vector<int> temp;
				temp.push_back(arr[i]);
				temp.push_back(arr[j]);
				temp.push_back(arr[k]);
				ans.push_back(temp);
				while(j<k && arr[j]==arr[j+1]) j++;
				while(j<k && arr[k]==arr[k-1]) k--;

				j++;
				k--;

			}else if(arr[i]+arr[j]+arr[k]>K){
				k--;
                   } 
			else {
                 j++;
               }
                }
                }
        }
	return ans;
}