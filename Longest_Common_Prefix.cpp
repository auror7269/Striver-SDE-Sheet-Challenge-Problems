string longestCommonPrefix(vector<string> &arr, int n)

{
    string ans="";
    for(int i=0; i<arr[0].size(); i++){
        char ch=arr[0][i];
        bool match=true;
        for(int j=1; j<arr.size(); j++){
            if(ch!=arr[j][i] || arr[j].size()<i){
                match=false;
                break;
            }
        }
        if(match==false) return ans;
        else ans+=ch;

    }

}

 

