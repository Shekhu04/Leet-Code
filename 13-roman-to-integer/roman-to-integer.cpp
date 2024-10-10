class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;  // Initialize variable to store the final integer result

        // Create a map to store the Roman numeral characters and their corresponding integer values
        unordered_map<char, int> mp {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        // Loop through each character in the string
        for(int i = 0; i < s.size(); i++) {
            // If the current character is smaller than the next character, subtract its value
            // This accounts for cases like IV (4), IX (9), XL (40), etc.
            if(mp[s[i]] < mp[s[i + 1]]) {
                ans = ans - mp[s[i]];  // Subtract the current character's value
            } 
            else {
                // Otherwise, add the value of the current character to the result
                ans = ans + mp[s[i]];
            }
        }

        // Return the final result which is the integer representation of the Roman numeral string
        return ans;
    }
};
