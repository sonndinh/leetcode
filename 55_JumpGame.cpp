class Solution {
public:
    // Optimized DP: O(n) time, constant space.
    bool canJump(vector<int>& nums) {
        // Index of the left-most entry that can reach the last entry.
        int left_most = nums.size() - 1;
        
        for (int i = (int)nums.size()-2; i >= 0; --i) {
            if (i + nums[i] >= left_most) {
                left_most = i;
            }
        }
        
        return left_most == 0;
    }
    
    // O(n^2) time, O(n) space.
    bool canJump1(vector<int>& nums) {
        vector<bool> tmp(nums.size(), false);
        tmp.back() = true;
        
        for (int i = (int)nums.size()-2; i >= 0; --i) {
            int val = nums[i];
            for (int j = i + 1; j <= i + val; ++j) {
                if (tmp[j] == true) {
                    tmp[i] = true;
                    break;
                }
            }
        }
        
        return tmp[0];
    }
};
