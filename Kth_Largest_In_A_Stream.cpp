 

class Kthlargest {

public:

priority_queue<int,vector<int>,greater<int>>pq;

int K;

    Kthlargest(int k, vector<int> &arr) {

       K=k;

       for(int i=0;i<arr.size();i++){

           pq.push(arr[i]);

           if(pq.size()>K)

           pq.pop();

       }

    }

 

    int add(int num) {

         pq.push(num);

         if(pq.size()>K){

             pq.pop();

         }

         return pq.top();

    }

 

};


