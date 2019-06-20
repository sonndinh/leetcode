class Solution {
public:
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> ret;
        int n = nums.size();
        if (n == 0) return ret;
        
        for (int i = 0; i <= n - k; ++i) {
            int temp = numeric_limits<int>::min();
            for (int j = 0; j < k; ++j) {
                temp = max(temp, nums[i+j]);
            }
            ret.push_back(temp);
        }
        
        return ret;
    }
    
    // Using the 3rd idea in the solution.
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        if (k == 1 || k == 0)
            return nums;
        
        vector<int> ret;
        int n = nums.size();
        vector<int> left = nums, right = nums;
        
        for (int i = 0; i < n; ++i) {
            left[i] = i % k > 0 ? max(left[i], left[i-1]) : left[i];
            int j = n - 1 - i;
            right[j] = (j+1) % k > 0 ? (j == n-1 ? right[j] : max(right[j], right[j+1])) : right[j];
        }
        
        for (int i = 0; i <= n-k; ++i) {
            if (i % k > 0) 
                ret.push_back(max(right[i], left[i + k - 1]));
            else
                ret.push_back(left[i + k - 1]);
        }
        
        return ret;
    }

    void update_deque(vector<int>& nums, deque<int>& deck, int i, int k) {
        // Remove element not in the current window.
        if (!deck.empty() && deck.front() == i - k)
            deck.pop_front();
        
        // Remove elements smaller than element at index i.
        while (!deck.empty() && nums[deck.back()] < nums[i]) {
            deck.pop_back();
        }
    }
    
    // Use a deque. Time O(n), space O(k) for deque.
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k == 1)
            return nums;
        
        // A double-ended queue containing indexes to the elements of array.
        deque<int> deck;
        vector<int> ret;
        
        int max_idx = 0;
        // Consider first k elements.
        for (int i = 0; i < k; ++i) {
            update_deque(nums, deck, i, k);
            deck.push_back(i);
            if (nums[i] > nums[max_idx])
                max_idx = i;
        }
        
        ret.push_back(nums[max_idx]);
        
        // Consider the remaining elements.
        for (int i = k; i < nums.size(); ++i) {
            update_deque(nums, deck, i, k);
            deck.push_back(i);
            ret.push_back(nums[deck.front()]);
        }
        
        return ret;
    }
};
