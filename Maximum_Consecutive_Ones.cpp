int longestSubSeg(vector<int> &arr , int n, int k){
    int i=0,j=0; 
    int ans=0; 
    int zero=0;

    while(j<n){
        if(arr[j]==0){
            zero++;
        }
        while(zero>k){
            if(arr[i]==0){
                zero--;
            }
            i++;
        }
        ans= max(ans, j-i+1);
        j++;
    }
    return ans;
}
