class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Initialize a vector of size 26 with all elements as 0
        // This vector keeps track of the frequency of each character ('a' to 'z')
        vector<int> arr(26, 0);

        // Counter to track the number of unique characters found
        int cnt = 0;

        // Loop through each character in the sentence
        for (int i = 0; i < sentence.length(); i++) {
            char ch = sentence[i];  // Current character
            int idx = ch - 'a';     // Calculate the index for this character (0 for 'a', 25 for 'z')

            // If the character is encountered for the first time
            if (arr[idx] == 0) {
                arr[idx]++;  // Mark the character as seen
                cnt++;       // Increment the count of unique characters
            }
        }

        // Check if all 26 characters are present (i.e., cnt == 26)
        // If true, return true (the sentence is a pangram), otherwise return false
        return true ? (cnt == 26) : false;
    }
};
