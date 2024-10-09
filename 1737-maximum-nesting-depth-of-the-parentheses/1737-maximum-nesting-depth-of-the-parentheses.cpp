class Solution {
public:
    int maxDepth(string s) {
        int count = 0; // Variable to track the current depth of nested parentheses
        int max_num = 0; // Variable to track the maximum depth encountered

        // Iterate over each character in the string
        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            // If the character is '(', it means we are going one level deeper
            if(c == '('){
                count++; // Increase the current depth
                // Update the maximum depth if the current depth is greater than max_num
                if(max_num < count) max_num = count;
            }
            // If the character is ')', it means we are going one level shallower
            else if(c == ')') count--;
        }
        return max_num; // Return the maximum depth encountered
    }
};
