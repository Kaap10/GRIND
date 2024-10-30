class RandomizedSet {

private:
    unordered_map<int, int> mp;
    vector<int> nums;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) {
            return false;
        }

        nums.push_back(val);
        mp[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) {
            return false;
        }

        int lastElememt = nums.back();
        int index = mp[val];

        nums[index] = lastElememt;
        mp[lastElememt] = index;

        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// good question 