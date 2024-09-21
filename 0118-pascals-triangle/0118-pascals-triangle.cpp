vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int row=1;row<=numRows;row++)
        {
            v.push_back(generateRow(row));
        }
        return v;
    }
};