class Solution {
public:
    // Function to check if two strings s and t are isomorphic
    bool isIsomorphic(string s, string t) {
        // Two unordered maps to store character mappings
        unordered_map<char, char> mp, mp2;

        // If the lengths of the strings are different, they can't be isomorphic
        if (s.length() != t.length()) return false;

        // Iterate through each character in the strings
        for (int i = 0; i < s.length(); ++i) {
            // Check if there is a conflicting mapping for s[i] in mp
            if (mp[s[i]] && mp[s[i]] != t[i]) return false;

            // Check if there is a conflicting mapping for t[i] in mp2
            if (mp2[t[i]] && mp2[t[i]] != s[i]) return false;

            // Create the mapping from s[i] to t[i] and from t[i] to s[i]
            mp[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }

        // If no conflicts were found, the strings are isomorphic
        return true;
    }
};
