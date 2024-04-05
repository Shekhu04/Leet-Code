class Solution {
public:
    string makeGood(string s) {
        string result = "";

        for (char &ch : s) {
            if (!result.empty() && (tolower(result.back()) == tolower(ch)) && (result.back() != ch)) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }
};
