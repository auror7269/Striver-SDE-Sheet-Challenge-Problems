int solve(int i,int j,string s1,string s2){

if(j==0){ 

    return i;

}
if(i==0) return j;
if(s1[i-1]==s2[j-1]){
    return solve(i-1,j-1,s1,s2);
}
else{
    return min((1+solve(i-1,j,s1,s2)),min( (1+solve(i-1,j-1,s1,s2)),
    (1+solve(i,j-1,s1,s2))));
}
}
int editDistance(string str1, string str2)
{
   string s1=str1;
    string s2=str2;
    int n1=str1.size();
    int n2=str2.size();
vector<int>prev(n2+1);
vector<int>curr(n2+1);
 for (int i=0;i<=n2;i++){
       prev[i]=i;    }
for (int i=1;i<=n1;i++){

    curr[0]=i;

    for (int j=1;j<=n2;j++){

if(s1[i-1]==s2[j-1]){

    curr[j]=prev[j-1];

}

else{

    curr[j]= min((1+prev[j]),min( (1+prev[j-1]),

    (1+curr[j-1])));

}

 

    }

    prev=curr;

}

return prev[n2];

 

}