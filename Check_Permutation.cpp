#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    map<char,int> mp;
    map<char,int> mp2;
    if(str1.size()!=str2.size()) return false;

    for(int i=0;i<str1.size();i++){
        mp[str1[i]]++;
        mp2[str2[i]]++;
    }
    for(int i=0;i<str1.size();i++){
        
    if(mp[str1[i]]!=mp2[str1[i]])  
        return false;

  }
  return true;
}