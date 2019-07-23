class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1, k = nums.size(), j = 0;
        
        while (j < k) {
            if (nums[j] == 0) {
                swap(nums[i+1], nums[j]);
                ++i;
                ++j;
            } else if (nums[j] == 2) {
                swap(nums[k-1], nums[j]);
                --k;
            } else {
                ++j;
            }
        }
    }
    
    void sortColors1(vector<int>& nums) {
        int count_zero = 0, count_one = 0, count_two = 0;
        for (int num : nums) {
            if (num == 0)
                ++count_zero;
            else if (num == 1)
                ++count_one;
            else 
                ++count_two;
        }
        
        int i = 0;
        for (int k = 0; k < count_zero; ++k, ++i) {
            nums[i] = 0;
        }
        for (int k = 0; k < count_one; ++k, ++i) {
            nums[i] = 1;
        }
        for (int k = 0; k < count_two; ++k, ++i) {
            nums[i] = 2;
        }
    }
};
