class Solution {
public:
    int beautySum(string s) {
        int ans = 0; // Variable to store the total beauty sum
        int n = s.size(); // Length of the input string

        // Loop to consider every possible starting point of a substring
        for(int i = 0; i < n; i++){
            map<char, int> m; // Map to store the frequency of characters in the current substring

            // Loop to consider every possible ending point of the substring starting at i
            for(int j = i; j < n; j++){
                m[s[j]]++; // Increment the frequency of the current character
                int max_freq = 0; // Variable to store the maximum frequency in the current substring
                int least_freq = INT_MAX; // Variable to store the minimum frequency in the current substring

                // Loop through the frequency map to find max and min frequencies
                for(auto a : m){
                    max_freq = max(max_freq, a.second);
                    least_freq = min(least_freq, a.second);
                }

                // Add the difference between max and least frequency to the answer
                ans += (max_freq - least_freq);
            }
        }
        return ans; // Return the total beauty sum
    }
};
