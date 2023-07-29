#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int> nse(n), pse(n), res(n, INT_MIN);
    for(int i=0; i<n; i++)
    {
        pse[i] = i;
        nse[i] = n-i-1;
    }

    stack<int> stk;
    for(int i=0; i<n; i++)
    {
        while(!stk.empty() && a[stk.top()]>a[i])
        {
            nse[stk.top()] = i-stk.top()-1;
            stk.pop();
        }
        stk.push(i);
    }

    while(!stk.empty()) stk.pop();

    for(int i=n-1; i>=0; i--)
    {
        while(!stk.empty() && a[stk.top()]>a[i])
        {
            pse[stk.top()] = stk.top()-i-1;
            stk.pop();
        }
        stk.push(i);
    }

    for(int i=0; i<n; i++)
    {
        int d = nse[i]+pse[i];
        res[d] = max(res[d], a[i]);
    }

    for(int i=n-2; i>=0; i--)
    if (res[i]<res[i+1]) res[i] = res[i+1];

    return res;
}