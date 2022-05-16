class Solution {
public:
    bool isValid(string s) {
    stack<char> p;
    for(int i = 0; i < s.length(); i++){
        // store '(', '[', '{' into a stack. 
        // if '(', '[' or '{' matches the top of the stack, then pop the top element. otherwise, return false.
        switch(s[i]){
            case '(': case '[': case '{':
                p.push(s[i]);
                break;
            case ')':
                if(!p.empty() && p.top() == '('){
                    p.pop();
                }else{
                    return false;
                }
                break;
            case ']':
                if(!p.empty() && p.top() == '['){
                    p.pop();
                }else{
                    return false;
                }
                break;
            case '}':
                if(!p.empty() && p.top() == '{'){
                    p.pop();
                }else{
                    return false;
                }
                break;
            default:
                return false;
            }
        }
        if(!p.empty())
            return false;
        return true;
    }
};
