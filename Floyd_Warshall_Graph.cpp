int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++){
        adj[i][i]=0;
    }
     for(auto it:edges){
            int u=it[0]-1;
            int v=it[1]-1;
            int wt=it[2];
        adj[u][v]=wt; 
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]!=1e9 && adj[k][j]!=1e9){
                        adj[i][j]=min(adj[i][j],(adj[i][k]+adj[k][j]));
                    }
                }
            }
        }
        return adj[src-1][dest-1];
}