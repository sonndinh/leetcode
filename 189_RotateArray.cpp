class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;
        
        // Number of entries moved.
        int count = 0;
        for (int start = 0; count < n; ++start) {
            int curr_idx = start;
            int curr_val = nums[curr_idx];
            
            do {
                int temp = nums[(curr_idx + k) % n];
                nums[(curr_idx + k) % n] = curr_val;
                curr_val = temp;
                curr_idx = (curr_idx + k) % n;
                ++count;
            } while (curr_idx != start);
        }
    }
};
