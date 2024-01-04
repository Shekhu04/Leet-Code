class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> ans = merge(intervals);
        return ans;
    }


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());
        int i = 1, prev1 = intervals[0][1], prev0 = intervals[0][0];

        while(i < n){
            if(intervals[i][0] >= prev0 && intervals[i][0] <= prev1){
                prev1 = max(prev1, intervals[i][1]);
                i++;
            }
            else{
                vector<int> temp;
                temp.push_back(prev0);
                temp.push_back(prev1);
                ans.push_back(temp);
                prev0 = intervals[i][0];
                prev1 = intervals[i][1];
                i++;
            }
        }

        vector<int> temp;
        temp.push_back(prev0);
        temp.push_back(prev1);
        ans.push_back(temp);

        return ans;
    }
};