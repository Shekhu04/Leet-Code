#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;  // Counter for unclosed '(' brackets
        int close = 0; // Counter for unmatched ')' brackets

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // If the character is an opening bracket
            if (s[i] == '(') {
                open++; // Increment the open counter
            } else {
                // If the character is a closing bracket
                if (open == 0) {
                    // If there are no unmatched opening brackets, this closing bracket is unmatched
                    close++; // Increment the close counter
                } else {
                    // There is an unmatched opening bracket available to pair with this closing bracket
                    open--; // Decrement the open counter
                }
            }
        }

        // The total number of additions required to make the string valid
        // is the sum of unmatched opening and closing brackets
        return (open + close);
    }
};
