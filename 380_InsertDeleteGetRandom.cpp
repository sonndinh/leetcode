class RandomizedSet {
    unordered_map<int, int> val_to_idx;
    vector<int> data;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (val_to_idx.find(val) != val_to_idx.cend())
            return false;
        data.push_back(val);
        val_to_idx[val] = data.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (val_to_idx.find(val) == val_to_idx.cend())
            return false;
        int idx = val_to_idx[val];
        val_to_idx.erase(val);
        if (idx != data.size() - 1) {
            data[idx] = data.back();
            val_to_idx[data[idx]] = idx;
        }
        data.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (data.size() > 0)
            return data[rand() % data.size()];
        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
