#include <string>
#include <bits/stdc++.h> 
int minCharsforPalindrome(string str) {
	int i=0, j=str.size()-1, trim=j, ans=0;

	while(i<j){
		if(str[i]==str[j]){
			i++;
			j--;
		}else {
			ans++;
			i=0;
			j=--trim;
		}
	}
	return ans;
	
}
