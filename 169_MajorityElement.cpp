class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        if (start == end - 1) 
            return nums[start];
        
        int mid = start + (end - start)/2;
        int left_val = helper(nums, start, mid);
        int right_val = helper(nums, mid, end);
        
        if (left_val == right_val)
            return left_val;
        
        // Need to find which one has larger number of occurrence.
        int count_left_val = 0, count_right_val = 0;
        for (int i = start; i < end; ++i) {
            if (nums[i] == left_val) {
                ++count_left_val;
            } else if (nums[i] == right_val) {
                ++count_right_val;
            }
        }
        
        return (count_left_val > count_right_val ? left_val : right_val);
    }
    
    // Divide and conquer.
    int majorityElement(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
    
    // Use hash map to track the number of occurrence of each number.
    int majorityElement2(vector<int>& nums) {
        unordered_map<int, int> count;
        int max_elem = nums[0];
        int max_count = 0;
        
        for (int num : nums) {
            ++count[num];
        }
        
        for (pair<const int, int>& p : count) {
            if (p.second > max_count) {
                max_count = p.second;
                max_elem = p.first;
            }
        }
        
        return max_elem;
    }
    
    // Sorting solution.
    int majorityElement1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        
        int count = 1;
        int curr = nums[0];
        for (int i = 1; i < size; ++i) {
            if (nums[i] == curr) {
                ++count;
            } else if (count > size/2) {
                return curr;
            } else {
                count = 1;
                curr = nums[i];
            }
        }
        
        return curr;
    }
};
