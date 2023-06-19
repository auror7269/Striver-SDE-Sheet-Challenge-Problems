#include <iostream>
#include <vector>
using namespace std;
int countsmaller(vector<int> &matrix, int mid){
    int low=0;
    int high=matrix.size()-1;
    while(low<=high){
        int md=(low+high)>>1;
        if(matrix[md]<=mid){
            low=md+1;
        }else{
            high=md-1;
        }
    }
    return low;
}

int getMedian(vector< vector<int> > &matrix)
{
    int low=1;
    int high=1e9;
    int n=matrix.size();
    int m=matrix[0].size();
    while(low<=high){
        int mid=(low+high)>>1;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=countsmaller(matrix[i],mid);
        }
        if(cnt<=(n*m)/2) low=mid+1;
        else high=mid-1;
    }
    return low;
}
int main()
{    int row = 5;
    int column[] = {5, 3, 4, 2, 1}; 
  
   
      
    vector<vector<int> > vec(row);
    for(int i = 0; i < row; i++)
    {   
       
        int col = column[i]; 
  
     
        vec[i] = vector<int>(col);
        for(int j = 0; j < col; j++)
        {
            vec[i][j] = j + 1;
        }    
    }
   
cout<<getMedian(vec);
}