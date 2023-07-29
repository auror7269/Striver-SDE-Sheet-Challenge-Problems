#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	int dp[n];
	for(int i=0;i<n;i++) dp[i]=rack[i];

	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(dp[j]<dp[i]){
				dp[i]=max(dp[i], rack[i]+dp[j]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,dp[i]);
	}
	return ans;
}