class Solution {
public:
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> ret;
        int n = nums.size();
        if (n == 0) return ret;
        
        for (int i = 0; i <= n - k; ++i) {
            int temp = numeric_limits<int>::min();
            for (int j = 0; j < k; ++j) {
                temp = max(temp, nums[i+j]);
            }
            ret.push_back(temp);
        }
        
        return ret;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.empty()) 
            return ret;
        if (k == 1)
            return nums;
        
        int max_all = nums[0];
        int max_trail = k == 2 ? 0 : numeric_limits<int>::min();
        for (int i = 0; i < k; ++i) {
            if (nums[i] > max_all) {
                max_all = nums[i];
            }
            if (i > 1 && nums[i] > max_trail) {
                max_trail = nums[i];
            }
        }
        
        ret.push_back(max_all);
        
        int n = nums.size();
        for (int i = 1; i <= n-k; ++i ) {
            int last_entry = nums[i + k - 1];
            max_all = max(nums[i], max(max_trail, last_entry));
            max_trail = (k == 2 ? 0 : max(max_trail, last_entry));
            ret.push_back(max_all);
        }
        
        return ret;
    }
};
