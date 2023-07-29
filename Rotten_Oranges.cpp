#include <queue>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int vis[n][m];
    int cntfresh=0;
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }else{
                vis[i][j]=0;
            }
            if(grid[i][j]==1) cntfresh++;
        }
    }
    int delrow[]={-1,0,+1,0};
    int delcol[]={0,+1,0,-1};
    int maxtimer=0;
    int cnt=0;
    while(!q.empty()){
        int r=q.front().first.first;
        int c = q.front().first.second;
        int tim = q.front().second;
        q.pop();
        maxtimer = max(maxtimer, tim);
        for(int i=0;i<4;i++){
            int ri = r+delrow[i];
            int ci = c + delcol[i];
            if(ri>=0 && ri<n && ci>=0 && ci<m && grid[ri][ci]==1
            && vis[ri][ci]!=2){
                vis[ri][ci]=2;
                q.push({{ri, ci}, tim+1});
                cnt++;
            }
        }
    }

    if(cnt!=cntfresh) return -1;

     return maxtimer;
    

}