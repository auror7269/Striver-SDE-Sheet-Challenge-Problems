bool searchMatrix(vector<vector<int>>& mat, int target) {
        if(mat[0][0]> target) return false;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==target) return true;
                else if(mat[i][j]>target){
                    break;
                }
            }
        }
        return false;

}