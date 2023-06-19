#include <bits/stdc++.h> 
bool isSafe(int node,vector<vector<int>> &mat,vector<int> color, int col){
    for(int k=0;k<mat.size();k++){
        if(k!=node && mat[k][node]==1 && color[k]==col) return false;
    }
    return true;
}
bool solve(int node, vector<vector<int>> &mat, vector<int> color, int m)
{
    if(node==mat.size()){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isSafe(node, mat, color, i )){
            color[node]=i;
            if(solve(node+1, mat, color, m)) return true;
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    int n=mat.size();
    vector<int> color(n,0);
   
   if(solve(0,mat,color, m)) return "YES";
   else {
       return "NO";
   }
}