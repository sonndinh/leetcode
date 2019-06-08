class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0;
        int num_ones = 0; // Number of 1s in the current window.
        
        for (int right = 0; right < A.size(); ++right) {
            if (A[right] == 1)
                ++num_ones;
            
            if (num_ones + K < right - left + 1) {
                if (A[left] == 1) 
                    --num_ones;
                ++left;
            }
        }
        
        return A.size() - left;
    }
};
