#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    vector<int>vt;
    for(auto x : arr)
    {
        maxHeap.push(x);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size()>maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(minHeap.size()==maxHeap.size())
        vt.push_back((minHeap.top()+maxHeap.top())/2);
        else if(maxHeap.size()==minHeap.size()+1)
        vt.push_back(maxHeap.top());
    }
    return vt;

}