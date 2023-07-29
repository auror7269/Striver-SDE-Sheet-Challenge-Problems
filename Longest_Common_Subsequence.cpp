#include<bits/stdc++.h>
int lcs(string s, string t)
{

	vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
	for(int i=0;i<s.size();i++){
		dp[i][0]=0;
	}
	for(int j=0;j<t.size();j++){
		dp[0][j]=0;
	}
	for(int i=1;i<=s.size();i++){
		for(int j=1;j<=t.size();j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
			}
		}
	}
	return dp[s.size()][t.size()];
}