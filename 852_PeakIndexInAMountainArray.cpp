class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 1, right = A.size() - 2;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
                return mid;
            } else if (A[mid] > A[mid - 1] && A[mid] < A[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    

	// Linear time but allows duplicates.
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
