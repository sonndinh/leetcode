class Solution {
public:
    const int LEFT_BOUND = 0, RIGHT_BOUND = 1;
    
    int binary_search(vector<int>& nums, int target, int type) {
        int left = 0, right = (int)nums.size() - 1;
        int idx = -1;
        
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) {
                if (type == LEFT_BOUND) {
                    if (mid > 0 && nums[mid-1] == target) {
                        right = mid - 1;
                    } else { // mid == 0 || nums[mid-1] != target
                        idx = mid;
                        break;
                    }
                } else {
                    if (mid < nums.size() - 1 && nums[mid+1] == target) {
                        left = mid + 1;
                    } else {
                        idx = mid;
                        break;
                    }
                }
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        if (idx == -1) {
            if (nums[left] == target)
                idx = left;
        }
        
        return idx;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1, -1};
        
        // Find the left occurrence.
        int left_idx = binary_search(nums, target, LEFT_BOUND);
        if (left_idx == -1)
            return {-1, -1};
        
        // Find the right occurrence.
        int right_idx = binary_search(nums, target, RIGHT_BOUND);
        return {left_idx, right_idx};
    }
};
