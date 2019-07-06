class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = (int)nums.size() - 1;
        int mid, size, left_size, right_size;
        
        while (left < right) {
            mid = left + (right - left)/2;
            size = (right - left + 1)/2;
            if (nums[mid] == nums[mid - 1]) {
                left_size = size - 1;
                if (left_size % 2 == 1) {
                    right = mid - 2;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] == nums[mid + 1]) {
                right_size = size - 1;
                if (right_size % 2 == 1) {
                    left = mid + 2;
                } else {
                    right = mid - 1;
                }
            } else {
                return nums[mid];
            }
        }
        
        return nums[left];
    }
};
