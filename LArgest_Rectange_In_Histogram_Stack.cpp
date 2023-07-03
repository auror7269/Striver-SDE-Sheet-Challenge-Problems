 #include <bits/stdc++.h> 
 void NSR(vector < int > & right, vector < int > & heights){
   stack<pair<int,int> > s;
   int psuedo=heights.size();
   for(int i=heights.size()-1;i>=0;i--){
     if(s.empty()) right.push_back(psuedo);
     else if(s.size()>0 && s.top().first<heights[i]) 
          right.push_back(s.top().second);
     else if(s.size()>0 && s.top().first>=heights[i]){
       while(s.size()>0 && s.top().first>=heights[i]){
         s.pop();
       }
       if(s.empty()) right.push_back(psuedo);
       else right.push_back(s.top().second);

     }

     s.push({heights[i], i});

   }
   reverse(right.begin(),right.end());
 }
 void NSL(vector < int > & left, vector < int > & heights ){
   stack<pair<int,int>> s;
   int psuedo=-1;
   for(int i=0;i<heights.size();i++){
     if(s.empty()) left.push_back(psuedo);
     else if(s.size()>0 && s.top().first<heights[i]) 
          left.push_back(s.top().second);
     else if(s.size()>0 && s.top().first>=heights[i]){
       while(s.size()>0 && s.top().first>=heights[i]){
         s.pop();
       }
       if(s.empty()) left.push_back(psuedo);
       else left.push_back(s.top().second);

     }

     s.push({heights[i], i});

   }
 }
 
 int largestRectangle(vector < int > & heights) {
   int n=heights.size();
  vector<int> left;
  vector<int> right;
  vector<int> area(n);
  vector<int> width(n);
  
  NSL(left, heights);  
  NSR(right, heights);
 
     
  for(int i=0;i<heights.size();i++){
      width[i]= right[i]-left[i]-1;
    }
  for(int i=0;i<width.size();i++){
       area[i]= width[i]*heights[i];
  }
  int maxi=INT_MIN;
  for(int i=0;i<area.size();i++){
    if(area[i]>maxi) maxi=area[i];
  }
  return maxi;
 

 }
