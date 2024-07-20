class Solution {
public:
    int maxDepth(string s) {
        int count = 0; // Variable to track the current depth of nested parentheses
        int max_num = 0; // Variable to track the maximum depth encountered

        // Iterate over each character in the string
        for(char c : s){
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

// Example: 1.(1)+((2))+(((3)))
// Step-by-step trace:

// ind=0 -> count=1, max_num=1.  // '(' increases depth to 1
// ind=1 -> count=1, max_num=1.  // '1' doesn't affect depth
// ind=2 -> count=0, max_num=1.  // ')' decreases depth to 0
// ind=3 -> count=0, max_num=1.  // '+' doesn't affect depth
// ind=4 -> count=1, max_num=1.  // '(' increases depth to 1
// ind=5 -> count=2, max_num=2.  // '(' increases depth to 2 (new max depth)
// ind=6 -> count=2, max_num=2.  // '2' doesn't affect depth
// ind=7 -> count=1, max_num=2.  // ')' decreases depth to 1
// ind=8 -> count=0, max_num=2.  // ')' decreases depth to 0
// ind=9 -> count=0, max_num=2.  // '+' doesn't affect depth
// ind=10 -> count=1, max_num=2.  // '(' increases depth to 1
// ind=11 -> count=2, max_num=2.  // '(' increases depth to 2
// ind=12 -> count=3, max_num=3.  // '(' increases depth to 3 (new max depth)
// ind=13 -> count=3, max_num=3.  // '3' doesn't affect depth
// ind=14 -> count=2, max_num=3.  // ')' decreases depth to 2
// ind=15 -> count=1, max_num=3.  // ')' decreases depth to 1
// ind=16 -> count=0, max_num=3.  // ')' decreases depth to 0

// Thus, the max depth is 3.
