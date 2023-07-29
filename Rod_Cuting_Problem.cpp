int profit(vector<int>& price ,int n ,int w,vector<vector<int>> &dp){

    if(n==0||w==0) return 0;

    if(dp[n][w]!=-1) return dp[n][w];

    if(n>w){

        return dp[n][w]=profit(price,n-1,w,dp);

    }

    else{

        int take=profit(price,n,w-n,dp)+price[n-1];
        int notake=profit(price,n-1,w,dp);

        return dp[n][w]=max(take,notake);

    }

}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    int w=n;
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=w;j++) dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
        if(i>j){
        dp[i][j]=dp[i-1][j];
        }
        else{
        int take=dp[i][j-i]+price[i-1];
        int notake=dp[i-1][j];
        dp[i][j]=max(take,notake);
        }
        }
    }

    return dp[n][w];

}
