class RandomizedSet {
    private:
        vector<int> nums; //randomized set
        unordered_map<int,int> m; //hashmap to map key(index in nums) and value
    public:
        RandomizedSet() {
            
        }
        
        bool insert(int val) {
            if (m.find(val) != m.end()) {return false;}
            nums.emplace_back(val);
            m[val] = nums.size() -1;
            return true;
        }
        
        bool remove(int val) {
            if (m.find(val) == m.end()){return false;}
            int last = nums.back();
            m[last] = m[val]; //change the key(index) of last to old_key(index) of val in m(map)
            nums[m[val]] = last; //change value at index_of_val to 'last' in nums
            nums.pop_back();
            m.erase(val);
            return true;
        }
        
        int getRandom() {
            return nums[rand() % nums.size()];
        }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */