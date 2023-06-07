

int findMajorityElement(int arr[], int n) {
	
	int cnt1=0;
	int el;
	for(int i=0;i<n;i++){
		if(cnt1==0){
			el=arr[i];
			cnt1=1;
		}else if(arr[i]==el){
			cnt1++;
		}else{
			cnt1--;
		}
	}
	cnt1=0;
	for(int i=0;i<n;i++){
		if(arr[i]==el) cnt1++;
		if(cnt1>(n/2)) return el;
	}
	return -1;
}