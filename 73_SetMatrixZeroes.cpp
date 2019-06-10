class Solution {
public:
    // Constant space.
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstCol = false;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (j == 0) {
                        firstCol = true;
                    } else {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        
        // Go through rows from 1.
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Go through columns from 1.
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Set zeroes for row 1.
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        
        // Set zeroes for column 1.
        if (firstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
	
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
