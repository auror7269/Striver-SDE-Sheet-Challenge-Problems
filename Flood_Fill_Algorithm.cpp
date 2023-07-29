void dfs(int x, int y, vector<vector<int>> &ans, vector<vector<int>> &image,
int &ini, int &newColor, int delrow[], int delcol[]){
    ans[x][y]=newColor;
    int n=image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++){
        int nrow = x + delrow[i];
        int ncol = y + delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
        image[nrow][ncol]==ini && ans[nrow][ncol]!=newColor){
            dfs(nrow,ncol, ans, image,ini,newColor, delrow, delcol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
   int ini = image[x][y];
   vector<vector<int>> ans;
   ans=image;
   int delrow[]={-1,0,+1,0};
   int delcol[]={0,+1,0,-1};
   dfs(x,y, ans, image, ini, newColor, delrow, delcol);
   return ans;
}