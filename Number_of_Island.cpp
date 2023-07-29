#include <queue>
void bfs(int row, int col,vector<vector<int>> &visited, 
int** arr,int n, int m){
   visited[row][col]=1;
   queue<pair<int,int>> q;
   q.push({row,col});
   while(!q.empty()){
      int r=q.front().first;
      int c=q.front().second;

      q.pop();
      for(int delrow=-1;delrow<=1;delrow++){
         for(int delcol=-1;delcol<=1;delcol++){
            int nrow = r+delrow;
            int ncol = c+delcol;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && visited[nrow][ncol]==0 && arr[nrow][ncol]==1){
               visited[nrow][ncol]=1;
               q.push({nrow,ncol});
            }
         }
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{  int cnt=0;
   vector<vector<int>> visited(n,vector<int>(m,0));
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(visited[i][j]==0 && arr[i][j]==1){
            cnt++;
            bfs(i,j,visited,arr,n,m);
         }
      }
   }
   return cnt;
}
