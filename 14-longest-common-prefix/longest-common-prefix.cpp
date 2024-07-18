class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans = "";  // Initialize the result string to store the longest common prefix

        // Sort the vector of strings lexicographically
        sort(v.begin(), v.end());

        // Get the number of strings in the vector
        int n = v.size();

        // Get the first and the last strings in the sorted vector
        string first = v[0], last = v[n - 1];

        // Iterate through the characters of the first and last strings
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            // If the characters at position i in both strings are not the same, return the current prefix
            if (first[i] != last[i]) {
                return ans;
            }
            // If the characters match, add the character to the result string
            ans += first[i];
        }

        // If the loop completes, the entire shortest string is the prefix
        return ans;
    }
};
