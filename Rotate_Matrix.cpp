#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &a, int n, int m)
{   
    // Write your code here
   int row=0,col=0;
   int prev,curr;
   int lastRow=n;
   int lastCol=m;
   while(row < lastRow && col < lastCol){
       if(row+1 == lastRow || col+1 ==lastCol) break;

       prev=a[row+1][col];
       for(int i=col;i<lastCol;i++){
           curr=a[row][i];
           a[row][i]=prev;
           prev=curr;
       }
       row++;

       for(int i=row;i<lastRow;i++){
           curr=a[i][lastCol-1];
           a[i][lastCol-1]=prev;
           prev=curr;
       }
       lastCol--;
       if(row<lastRow){
 for (int i = lastCol-1; i >= col; i--) 
            { 
                curr = a[lastRow-1][i]; 
                a[lastRow-1][i] = prev; 
                prev = curr; 
            } 
        } 
        lastRow--; 
        //for the first row which is in bounds
        if (col < lastCol) 
        { 
            for (int i = lastRow-1; i >= row; i--) 
            { 
                curr = a[i][col]; 
                a[i][col] = prev; 
                prev = curr; 
            } 
        } 
        col++; 
    } 
 

}