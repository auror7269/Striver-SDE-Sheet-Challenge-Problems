
int solve(vector<int> &values, vector<int> &weights,int index, int capacity,
vector<vector<int>> &dp){
	if(index==0){
		if(weights[0]<=capacity) return values[0];
		else return 0;
	}
	if(dp[index][capacity]!=-1) return dp[index][capacity];

	int take=0;
	if(weights[index]<=capacity){
		take = values[index]+solve(values, weights, index-1, capacity-weights[index],
		dp);
	}
	int nottake = solve(values,weights,index-1,capacity,dp);

	return dp[index][capacity]= max(take,nottake);
}



int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n,vector<int>(w+1,-1));

	return solve(values, weights,n-1,w,dp);
}