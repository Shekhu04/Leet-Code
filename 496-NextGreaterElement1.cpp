class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int ans=-1;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            for(int j=i+1;j<nums2.size();j++)
            {
                if(nums2[j]>nums2[i]) 
                {
                    ans=nums2[j]; break;
                }
            }
            mp[nums2[i]]=ans;
            ans=-1;
        }
        vector<int>v;
        for(auto value:nums1)
        {
            if(mp.find(value)!=mp.end()) 
            {
                auto it = mp.find(value);
                v.push_back(it->second);
            }
            else 
            {
                v.push_back(-1);
            }
        }
        return v;
    }
};
