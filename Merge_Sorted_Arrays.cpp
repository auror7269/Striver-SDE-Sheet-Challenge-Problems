

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
	int right=arr2.size()-1;
	int left=arr1.size()-arr2.size()-1;
	int res=arr1.size()-1;
	while(left>=0 && right>=0){
		if(arr1[left]>=arr2[right]){
			arr1[res]=arr1[left];
			res--;
			left--;
		}else{
			arr1[res]=arr2[right];
			res--;
			right--;
		}
	}
	while(right>=0){
		arr1[res]=arr2[right];
		right--;
		res--;
	}
	return arr1;
}