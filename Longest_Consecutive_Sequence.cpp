

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
  
    sort(arr.begin(),arr.end());
    int lastsmaller=INT_MIN;
    int largest=1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]-1==lastsmaller){
            cnt++;
            lastsmaller=arr[i];
        }
       
        if(arr[i]!=lastsmaller){
            lastsmaller=arr[i];
            cnt=1;
        }
         largest=max(largest,cnt);
        
    }
    return largest;
}