#include <bits/stdc++.h> 

class minStack
{
	vector<pair<int,int>> v;
	public:
		
	
		minStack() 
		{ 
			
		}
		
		
		void push(int num)
		{
			if(v.empty()) v.push_back({num,num});
			else {
				int minval=min(v.back().second, num);
				v.push_back({num, minval});
			}
		}
		
		
		int pop()
		{
			if(v.empty()) return -1;
			else {
				int t=v.back().first;
				v.pop_back();
				return t;
			}
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(v.empty()) return -1;
			else {
				int t=v.back().first;
			
				return t;
			}
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(v.empty()) return -1;
			else {
				return v.back().second;
			}
		}
};