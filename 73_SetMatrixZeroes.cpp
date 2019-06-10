class Solution {
public:
    // O(m + n) space.
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> rows, cols;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        for (auto it = rows.begin(); it != rows.end(); ++it) {
            for (int j = 0; j < n; ++j) {
                matrix[*it][j] = 0;
            }
        }
        
        for (auto it = cols.begin(); it != cols.end(); ++it) {
            for (int i = 0; i < m; ++i) {
                matrix[i][*it] = 0;
            }
        }
    }
    
    // O(n^2) space.
    void setZeroes1(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // Record all 0s.
        vector<pair<int, int>> zeros;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0)
                    zeros.emplace_back(i, j);
            }
        }
        
        for (pair<int, int>& p : zeros) {
            // Set rows.
            for (int i = 0; i < m; ++i) {
                matrix[i][p.second] = 0;
            }
            // Set columns.
            for (int j = 0; j < n; ++j) {
                matrix[p.first][j] = 0;
            }
        }
    }
};
