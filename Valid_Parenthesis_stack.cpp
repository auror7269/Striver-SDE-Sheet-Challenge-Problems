bool isValidParenthesis(string expression)
{
    stack<char> s;
    for(int i=0;i<expression.size();i++){
        if(expression[i]=='{'||expression[i]=='('||expression[i]=='['){
            s.push(expression[i]);
        }else if(expression[i]=='}'||expression[i]==')'||expression[i]==']'){
            if(s.empty()) return false;
            else {
              char c = s.top();
              s.pop();
             if(expression[i]=='}' && c=='{'){
                 continue;
             }else  if(expression[i]==')' && c=='('){
                 continue;
             }else  if(expression[i]==']' && c=='['){
                 continue;
             }else{
                 return false;
             }
            }
        }
    }
    if(s.empty()) return true;
    
    return false;
}