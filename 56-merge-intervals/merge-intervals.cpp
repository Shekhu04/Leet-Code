class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();  // Get the number of intervals

        // Sort the intervals based on the starting time.
        // This is necessary to make sure that any overlapping intervals are adjacent.
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;  // Vector to store the merged intervals

        // Iterate through each interval
        for(int i = 0; i < n; i++) {
            // If the result array is empty or the current interval does not overlap
            // with the last interval in the result array, add the current interval to the result
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                // If the current interval overlaps with the last interval in the result array,
                // merge them by updating the end time of the last interval in the result array
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        // Return the merged intervals
        return ans;
    }
};
