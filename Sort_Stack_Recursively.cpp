#include <bits/stdc++.h> 
void insert(stack<int> &s, int temp){
	if(s.size()==0|| (!s.empty() && s.top()<temp)){
		s.push(temp);
		return;
	}
	int val=s.top();
	s.pop();
	insert(s, temp);
	s.push(val);
	return;
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}
	int temp=stack.top();
	stack.pop();
	sortStack(stack);
	insert(stack, temp);
	return;
}