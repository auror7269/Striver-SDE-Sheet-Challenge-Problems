string longestPalinSubstring(string str) {
    int n=str.size();
    vector<vector<int>> dp(n, vector<int>(n,0));
    string ans;
    int maxlen=0;
    for(int diff=0;diff<n;diff++){
        for(int i=0,j=i+diff;j<n;i++,j++){
            if(i==j) dp[i][j]=1;

            else if(diff==1) dp[i][j]=str[i]==str[j]?2:0;

            else{
                if(str[i]==str[j] && dp[i+1][j-1]){
                    dp[i][j]= dp[i+1][j-1]+2;
                }
            }
            if(dp[i][j]){
                if(j-i+1>maxlen){
                    maxlen=j-i+1;
                    ans = str.substr(i,maxlen);
                }
            }
        }
    }
    return ans;
}