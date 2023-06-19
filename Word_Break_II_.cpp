#include <bits/stdc++.h> 
vector<string> solve(int ind, string &s, unordered_map<int, vector<string>> &dp,
unordered_set<string> &dictset, int n){
    if(ind==n){
      return {""};
    }
    if(dp.find(ind)!=dp.end()){
        return dp[ind];
    }
    vector<string> subpart, completepart;
    string word="";
    for(int i=ind;i<n;i++){
        word.push_back(s[i]);
        if(dictset.count(word)==0){
            continue;
        }
        subpart=solve(i+1, s, dp, dictset, n);
        for(int j=0; j<subpart.size();j++){
            if(subpart[j].size()!=0){
                string temp=word;
                temp.append(" ");
                temp.append(subpart[j]);
                subpart[j]=temp;
            }else{
                subpart[j]=word;
            }
        }
        for(int j=0;j<subpart.size();j++){
            completepart.push_back(subpart[j]);
        }
    }
    dp[ind]=completepart;
    return dp[ind];
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<int, vector<string>> dp;

    unordered_set<string> dictset;
    for(int i=0;i<dictionary.size();i++){
        dictset.insert(dictionary[i]);
    }
     return solve(0,s , dp, dictset, s.size());

}