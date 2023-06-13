#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long left=0;
    long right=n-1;
    long res=0;
    long leftmax=0, rightmax=0;

    while(left<=right){
        if(arr[left]<=arr[right]){
            if(arr[left]>=leftmax) leftmax=arr[left];
            else res+=leftmax-arr[left];

            left++;
        }else{
            if(arr[right]>=rightmax) rightmax=arr[right];
            else res+=rightmax-arr[right];

            right--;
        }
    }
    return res;
}