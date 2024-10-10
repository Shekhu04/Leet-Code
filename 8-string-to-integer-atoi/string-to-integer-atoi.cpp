class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        
        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Determine the sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;  // Set sign to -1 if negative sign is encountered
            }
            i++;  // Move to the next character after the sign
        }

        // Step 3: Convert digits to integer
        long long result = 0;  // Use long long to handle overflow cases
        while (i < n && (s[i] >= '0' && s[i] <= '9')) {  // Manual check for digits
            result = result * 10 + (s[i] - '0');
            
            // Step 4: Check for overflow and underflow
            if (result * sign >= INT_MAX) {
                return INT_MAX;  // Return INT_MAX if overflow occurs
            }
            if (result * sign <= INT_MIN) {
                return INT_MIN;  // Return INT_MIN if underflow occurs
            }
            i++;  // Move to the next character
        }

        return (result * sign);  // Apply sign and return the result
    }
};
