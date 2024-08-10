#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        // Base case: when n is 1, return the first term in the sequence which is "1"
        if(n == 1) return "1";

        // Recursive call to get the (n-1)th term in the sequence
        string s = countAndSay(n-1);

        // Variable to count the frequency of consecutive identical characters
        int freq = 0;

        // Result string to store the nth term in the sequence
        string result = "";

        // Loop through the characters of the string s (the (n-1)th term)
        for(int i = 0; i < s.length(); i++) {
            // Increment the frequency count for the current character
            freq++;

            // If we reach the end of the string or the next character is different
            if(i == s.length() - 1 || s[i] != s[i + 1]) {
                // Append the frequency and the character to the result string
                result = result + to_string(freq) + s[i];
                // Reset the frequency counter for the next group of characters
                freq = 0;
            }
        } 
        // Return the result string, which represents the nth term in the sequence
        return result;
    }
};
