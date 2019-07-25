class Solution {
public:
    void add_range(vector<string>& ret, long left, long right) {
        if (left + 1 < right) {
            if (left + 1 == right - 1) {
                ret.push_back(to_string(left+1));
            } else {
                ret.push_back(to_string(left+1) + "->" + to_string(right-1));
            }
        }
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        if (nums.empty()) {
            if (lower == upper)
                ret.push_back(to_string(lower));
            else 
                ret.push_back(to_string(lower) + "->" + to_string(upper));
            return ret;
        }

        if (nums[0] > lower) {
            if (nums[0] - 1 == lower)
                ret.push_back(to_string(lower));
            else 
                ret.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
        }
        
        for (int i = 1; i < (int)nums.size(); ++i) {
            add_range(ret, nums[i-1], nums[i]);
        }

        if (nums.back() < upper) {
            if (nums.back() + 1 == upper)
                ret.push_back(to_string(upper));
            else 
                ret.push_back(to_string(nums.back() + 1) + "->" + to_string(upper));
        }

        return ret;
    }
};
