class Solution {
public:
    void bt(int idx, int k, int n, vector<int> &comb, vector<vector<int>> &ans) {
        if(comb.size() == k) {
            ans.push_back(comb);
            return;
        }
        for(int i = idx; i <= n; i++) {
            comb.push_back(i);
            bt(i + 1, k, n, comb, ans);
            comb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        bt(1, k, n, comb, ans);
        return ans;
    }
};