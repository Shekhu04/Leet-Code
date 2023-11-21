class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> map{{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, 
		{90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        int l = map.size()-1;
        string s="";
        
        while(num!=0){
            while(map[l].first>num){
                l--;
            }
            s += map[l].second;
            num -= map[l].first;
        }
        return s;
    }
};
