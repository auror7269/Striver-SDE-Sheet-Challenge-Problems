#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    int* arr;
    int top1=-1;
    int max_size;
    Stack(int capacity) {
         arr=new int[capacity];
         top1=0;
         max_size=capacity;
        
    }

    void push(int num) {
        if(top1!=max_size){
            arr[top1++]=num;
        }
    }

    int pop() {
      if (top1 != 0) {
        top1--;
        return arr[top1];
      }
      return -1;
    }
    
    int top() {
        return (top1!=0)?(arr[top1-1]):(-1);
    }
    
    int isEmpty() {
        return (top1==0)?(1):(0);
    }
    
    int isFull() {
        return (top1==max_size);
    }
    
};