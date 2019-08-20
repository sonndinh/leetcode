class Solution {
public:
    // Floyd's tortoise and hare cycle detection algorithm.
    // Reference: https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_Tortoise_and_Hare.
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        // Indexes of the next elements for the tortoise and hare.
        // Start from the first element.
        int tortoise = 0, hare = 0;
        
        // Start from the first element, move tortoise 1 step and 
        // hare 2 steps at a time until they end up in the same element.
        while (tortoise == 0 || nums[tortoise] != nums[hare]) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }
        
        // Move the tortoise back to the first element and move both the 
        // the tortoise and hare one step at a time until they point to elements with the same value.
        tortoise = 0;
        while (nums[tortoise] != nums[hare]) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return nums[tortoise];
    }
    
    
    int findDuplicate1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] == nums[i-1])
                return nums[i];
        }
        
        // Will not reach here.
        return -1;
    }
};
