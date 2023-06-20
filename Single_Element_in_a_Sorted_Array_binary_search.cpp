int singleNonDuplicate(vector<int>& arr)
{	int low=0;
int high=arr.size()-2;
while(low<=high){
	int mid = (low+high)>>1;
	if(arr[mid]==arr[mid^1]){//left half
	  low=mid+1;
	}else{
		high=mid-1;
	}
}
return arr[low];
}