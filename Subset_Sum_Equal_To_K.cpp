int helper(vector < int > & arr, int n, int k, vector < vector < int >> & memo) {
    if (n <= 0) {
      
        if (k == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if (memo[n][k] != -1) {
        return memo[n][k];
    }
      int x = helper(arr, n - 1, k, memo);
    int y = 0;
    if(k - arr[n-1] >= 0){
        y = helper(arr, n - 1, k - arr[n-1], memo);    
    }
    memo[n][k] = x || y;

    return memo[n][k];
}

bool subsetSumToK(int n, int k, vector < int > & arr) {
    vector < vector < int >> memo(n+1, vector < int > (k+1, -1));
    int ans = helper(arr, n, k, memo);

    if (ans == 1) {
        return true;
    } else {
        return false;
    }
}