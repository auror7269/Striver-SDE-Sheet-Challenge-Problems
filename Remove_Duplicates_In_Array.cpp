int removeDuplicates(vector<int> &arr, int n) {
	
	int count=0;
	for(int i=0;i<n;i++){
		if(arr[i]!=arr[i+1]) count++;
	}
	return count;
	
}