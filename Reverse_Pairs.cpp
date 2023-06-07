#include <bits/stdc++.h> 
int merge(vector<int> &arr,int low, int mid, int high){
	int count=0;
	int j=mid+1;
	for(int i=low;i<=mid;i++){
		while(j<=high && arr[i]> (2LL * arr[j])){
			j++;
		}
		count+= (j-(mid+1));
	}
	int left = low, right = mid+1;
	vector<int> temp;
	while(left<=mid && right<=high){
		if(arr[left]<=arr[right]){
			temp.push_back(arr[left]);
			left++;
		}else{
			temp.push_back(arr[right]);
			right++;
		}
	}
	while(left<=mid){
		temp.push_back(arr[left]);
		left++;
	}
	while(right<=high){
		temp.push_back(arr[right]);
		right++;
	}
	for(int i=low;i<=high;i++){
		arr[i]=temp[i-low];
	}
	return count;
}

int mergesort(vector<int> &arr, int low, int high){
	
	if(low>=high) return 0;
	int mid= (low+high)/2;
	int cnt=mergesort(arr, low, mid);
	cnt+= mergesort(arr,mid+1, high);
	cnt+=merge(arr, low, mid, high);
	return cnt;
}

int reversePairs(vector<int> &arr, int n){
	
	return mergesort(arr, 0, n-1);
}