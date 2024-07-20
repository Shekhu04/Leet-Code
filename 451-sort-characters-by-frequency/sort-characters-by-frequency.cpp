class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp; // Step 1: Create a map to count the frequency of each character

        // Step 2: Populate the frequency map
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }

        string ans = ""; // Step 3: Initialize the result string
        priority_queue<pair<int,char>> pq; // Step 4: Create a max-heap (priority queue) to store characters by frequency

        // Step 5: Push each character and its frequency into the priority queue
        for(auto i:mp)
            pq.push({i.second,i.first});

        // Step 6: Build the result string by extracting from the priority queue
        while(!pq.empty()){
            int n = pq.top().first; // Get the frequency of the character

            while(n--){
                ans += pq.top().second; // Add the character to the result string
            }
            pq.pop(); // Remove the character from the priority queue
        }

        return ans; // Return the result string
    }
};
