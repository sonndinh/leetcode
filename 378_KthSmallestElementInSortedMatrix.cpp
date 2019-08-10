class Solution {
public:
    struct ValCompare {
        // Each vector contains: x-coordinate, y-coordinate, number value.
        bool operator() (const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        }
    };
    
    // Time O(klgn), space O(n).
    int kthSmallest(vector<vector<int>>& matrix, int k) {
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
