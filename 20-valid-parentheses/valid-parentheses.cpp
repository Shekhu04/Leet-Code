class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);  // Push all opening brackets
            } else {
                // If stack is empty or the top doesn't match the corresponding opening bracket, return false
                if (st.empty() || 
                    (c == ')' && st.top() != '(') || 
                    (c == ']' && st.top() != '[') || 
                    (c == '}' && st.top() != '{')) {
                    return false;
                }
                st.pop();  // Pop the matching opening bracket
            }
        }
        return st.empty();  // If stack is empty at the end, parentheses are valid
    }
};
