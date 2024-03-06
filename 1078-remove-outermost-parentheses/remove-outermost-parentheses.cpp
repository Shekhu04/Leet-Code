
class Solution {
public:
    string removeOuterParentheses(string s) {
       string ans = "";
       int count = 0;
       for(char ch:s) {
           if(ch=='(' && count == 0){
               count++;
           }
           else if(ch=='(' && count >= 1){
               ans = ans + ch;
               count++;
           }
           else if(ch == ')' && count > 1){
               ans = ans+ch;
               count--;
           }
           else if(ch==')' && count == 1){
               count --;
           }
       }
       return ans; 
    }
};