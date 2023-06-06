#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	
	sort(arr.begin(),arr.end());
	int sum1=0;
	int dup;
	for(int i=0;i<n;i++){
		if(arr[i]==arr[i+1]){
			dup=arr[i];
                } else {

                  sum1 += arr[i];
                }
        }
	
	int sum=n*(n+1);
	sum=sum/2;
	int mis=sum-sum1;
	pair<int,int> ans={mis,dup};
	return ans;
	
}
