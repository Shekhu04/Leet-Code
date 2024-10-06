class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans ="";

        for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // Check for '(' when count is 0 (first opening parenthesis of an outer group)
        if (c == '(' && count == 0) {  
            count++;
        }
        // For subsequent '(' when count is 1 or more, add to answer
        else if (c == '(' && count >= 1) {
            ans += c;
            count++;
        }
        // For ')' that closes an inner group, add to answer if count is greater than 1
        else if (c == ')' && count > 1) {
            ans += c;
            count--;
        }
        // For ')' that closes an outer group
        else if (c == ')' && count == 1) {
            count--;
        }
      }
        return ans;
    }
};  