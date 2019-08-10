class Solution {
public:
    // Binary search using element values instead of indexes of elements.
    // Time O(nlgnlg(max-min)) where max, min are the maximum and minimum numbers in the matrix.
    // Space O(1).
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        
        // The invariant is that in each iteration [left, right] contains the k-th element.
        while (left < right) {
            int mid = left + (right - left)/2;
            int count = 0;
            
            // Count the number of elements less than or equal to mid in the matrix.
            for (int i = 0; i < n; ++i) {
                int idx = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                count += idx;
            }
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    struct ValCompare {
        // Each vector contains: x-coordinate, y-coordinate, number value.
        bool operator() (const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        }
    };
    
    // Time O(klgn), k is O(n^2), so it is O(n^2lgn). Space O(n).
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>>, ValCompare> min_heap;
        for (int i = 0; i < n; ++i) {
            min_heap.push({i, 0, matrix[i][0]});
        }
        
        int i = 0;
        vector<int> next;
        while (i < k) {
            next = min_heap.top();
            min_heap.pop();
            if (next[1] < n-1) {
                min_heap.push({next[0], next[1]+1, matrix[next[0]][next[1]+1]});
            }
            ++i;
        }
        
        return next[2];
    }
};
