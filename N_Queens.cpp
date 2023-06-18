
void solve(int col, int n, vector<vector<int>> &ans, 
vector<vector<int>> &ds,vector<int> &leftrow,
vector<int> &upperdiagonal, vector<int> &lowerdiagonal){
    if(col==n){
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(ds[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        if(leftrow[i]==0 && upperdiagonal[n-1+col-i]==0 && lowerdiagonal[i+col]==0){
            ds[i][col]=1;
            leftrow[i]=1;
            upperdiagonal[n-1+col-i]=1;
            lowerdiagonal[i+col]=1;
            solve(col+1, n, ans, ds, leftrow, upperdiagonal, lowerdiagonal);
            ds[i][col]=0;
            leftrow[i]=0;
            upperdiagonal[n-1+col-i]=0;
            lowerdiagonal[i+col]=0;
            
        }
    }
    return ;
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    
    vector<int> leftrow(n,0), upperdiagonal(2*n-1,0), lowerdiagonal(2*n-1, 0);
    solve(0,n, ans, board, leftrow, upperdiagonal, lowerdiagonal);
    return ans;
}