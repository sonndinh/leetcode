class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = numeric_limits<int>::min();
        int running_min = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = nums[i] + (i == 0 ? 0 : nums[i-1]);
            if (ret < nums[i] - running_min) {
                ret = nums[i] - running_min;
            }
            if (running_min > nums[i]) {
                running_min = nums[i];
            }
        }
        
        return ret;
    }
};
