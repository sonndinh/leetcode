class Solution {
public:
    void sortColors(vector<int>& nums) {
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
