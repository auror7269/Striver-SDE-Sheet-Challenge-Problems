int matrixMultiplication(vector<int> &arr, int N)
{
   vector<vector<int>> dp(N,vector<int>(N));
   for(int len = 2; len < N; len++){
       for(int row = 0; row < N - len; row++){
           int col = row + len;
           dp[row][col] = INT_MAX;
           for(int k = row + 1; k < col; k++){
               dp[row][col] = min(dp[row][col],
               dp[row][k] + dp[k][col] +
               arr[row] * arr[k] * arr[col]
               );
           }
       }
   }
   return dp[0][N - 1];
}
