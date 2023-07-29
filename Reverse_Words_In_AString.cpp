#include<stack>

 string reverseString(string &str){ 
stack<string> s; 
string a; 
for(int i=0;i<str.size();i++){  
if(str[i]!=' '){   
a+=str[i]; 
 } 
 if(str[i]==' ' || i==str.size()-1){ 
  if(a.size()!=0){   
 s.push(a);  
  a.clear();
   } 
 } 
} 
string t; 
while(s.size()>0){  
t+=s.top(); 
 s.pop();  
if(s.size()!=0){  
 t+=' '; 
 } 
}
 return t;
 }