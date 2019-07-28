class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int max_val = A[0], max_idx = 0;
        for (int i = 1; i < A.size()-1; ++i) {
            if (A[i] > A[i-1] && A[i] >= A[i+1]) {
                max_idx = max_val < A[i] ? i : max_idx;
                max_val = max(max_val, A[i]);
            }
        }

        return max_idx;
    }
};
