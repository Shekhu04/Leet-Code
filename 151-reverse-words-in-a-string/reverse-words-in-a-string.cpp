class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(); // Get the length of the input string
        int i = 0; // Initialize an index to traverse the string
        string ans = ""; // Initialize the result string

        // Loop until we have processed the entire string
        while (i < n) {
            string temp = ""; // Temporary string to hold the current word

            // Skip any leading spaces
            while (s[i] == ' ' && i < n) {
                i++; // Move the index forward
            }

            // Collect characters of the current word
            while (s[i] != ' ' && i < n) {
                temp += s[i]; // Append the current character to temp
                i++; // Move the index forward
            }

            // If a non-empty word was found
            if (temp.size() > 0) {
                // If ans is empty, directly assign temp to it
                if (ans.size() == 0) {
                    ans = temp; 
                } else {
                    // Otherwise, prepend the current word to ans
                    ans = temp + " " + ans; 
                }
            }
        }
        return ans; // Return the final reversed string
    }
};
