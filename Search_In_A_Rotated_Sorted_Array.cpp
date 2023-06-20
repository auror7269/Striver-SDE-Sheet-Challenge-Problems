#include <iostream>
int search(int* arr, int n, int key) {
   int low=0;
   int high=n-1;

   while(low<=high){
       int mid = (low+high)>>1;
       if(arr[mid]==key){
           return mid;
       }
       if(arr[low]<=arr[mid]){
           if(key>=arr[low] && key<=arr[mid]){
               high=mid-1;
           }else{
               low=mid+1;
           }
       }
       if(arr[mid]<=arr[high]){
           if(key>=arr[mid] && key<=arr[high]){
               low=mid+1;
           }else{
               high=mid-1;
           }
       }
   }
   return -1;
}