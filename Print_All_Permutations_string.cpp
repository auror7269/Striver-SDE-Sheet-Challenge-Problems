#include <bits/stdc++.h> 
void func(string &s, int index, vector<string> &ans)

{
    if (index == s.length())
    {
        ans.push_back(s);
        return;
    }
    for (int i = index; i < s.length(); i++)

    {
        swap(s[i],s[index]);
        func(s, index + 1 , ans);
        swap(s[i],s[index]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    func(s, 0, ans);

    return ans;

}