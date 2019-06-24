class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int diff = numeric_limits<int>::max();
        int sum;
        for (int i = 0; i < nums.size(); ++i) {
            int leftover = target - nums[i];
            for (int j = i+1, k = (int)nums.size()-1; j < k;) {
                if (nums[j] + nums[k] == leftover) {
                    return target;
                }
                if (abs(nums[j] + nums[k] - leftover) < diff) {
                    diff = abs(nums[j] + nums[k] - leftover);
                    sum = nums[i] + nums[j] + nums[k];
                }
                
                if (nums[j] + nums[k] > leftover) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        
        return sum;
    }
};
