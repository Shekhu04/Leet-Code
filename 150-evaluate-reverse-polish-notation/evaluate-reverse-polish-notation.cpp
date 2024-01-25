class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        long op1, op2;
        unordered_set<string> op = {"+", "-", "/", "*"};
        for (auto i : tokens) {
            if (op.find(i) == op.end()) {
                st.push(stoi(i));
            } else {
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();

                if (i == "+") {
                    op1 = op1 + op2;
                } else if (i == "-") {
                    op1 = op1 - op2;
                } else if (i == "/") {
                    if (op2 == 0) {
                        return INT_MAX;
                    }
                    op1 = op1 / op2;
                } else if (i == "*") {
                    op1 = op1 * op2;
                }
                st.push(op1);
            }
        }
        return st.top();
    }
};