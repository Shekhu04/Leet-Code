class Solution {
public:
    static bool cmp(pair<char,int>& a,pair<char,int>& b)
    {
        return a.second>b.second;    //sorting with respect to the frequency of characters
    }
    
    string frequencySort(string s) {
        vector<pair<char,int>> v(256);   //declare a vector of pair where we can store character and their frequency
        
        for(auto it:s)
        {
            v[it].first=it;           //storing the character
            v[it].second+=1;          //storing its frequency
        }
        
        sort(v.begin(),v.end(),cmp);  //sorting the vector
        
        string ans;                   //declaring a string to store ans
        
        for(auto it:v) 
        {
            for(int j=0;j<it.second;j++) ans+=it.first;    //running the second loop till we complete storing all the frequency
        }
        
        return ans;
    }
};