class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for (int i = n-2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }
        
        if (idx >= 0) {
            int val = numeric_limits<int>::max();
            int target_idx = -1; // Index of the smallest number that are greater than nums[idx].
            for (int i = n-1; i > idx; --i) {
                if (nums[i] < val && nums[i] > nums[idx]) {
                    val = nums[i];
                    target_idx = i;
                }
            }
            
            swap(nums[idx], nums[target_idx]);
            sort(nums.begin() + idx + 1, nums.end());
        } else {
            sort(nums.begin(), nums.end());
        }
    }
};
