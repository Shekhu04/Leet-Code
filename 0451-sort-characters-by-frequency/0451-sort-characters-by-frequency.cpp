class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character using a map
        map<char,int> mp; // Stores the frequency of each character
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++; // Increment frequency for each character
        }
        
        string ans = ""; // To store the final sorted string

        // Step 2: Use a priority queue to sort characters by their frequencies in descending order
        priority_queue<pair<int,char>> pq; // Max-heap to store characters and their frequencies
        for(auto it : mp){
            pq.push({it.second , it.first}); // Push frequency and character to the max-heap
        }

        // Step 3: Build the result string by repeatedly adding characters from the max-heap
        while(!pq.empty()){
            int n = pq.top().first; // Get the frequency of the character at the top of the heap
            // Append the character n times to the answer
            while(n--){
                ans += pq.top().second;
            }
            pq.pop(); // Remove the current character from the heap
        }

        return ans; // Return the final sorted string
    }
};
