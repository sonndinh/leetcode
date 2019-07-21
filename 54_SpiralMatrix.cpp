class Solution {
public:
    void helper(const vector<vector<int>>& matrix, int row_off, int col_off, vector<int>& output) {
        int m = matrix.size(), n = matrix[0].size();
        
        if (m - 2*row_off >= 2 && n - 2*col_off >= 2) {
            for (int j = col_off; j < n - col_off; ++j) {
                output.push_back(matrix[row_off][j]);
            }
            for (int i = row_off+1; i < m - row_off; ++i) {
                output.push_back(matrix[i][n-1-col_off]);
            }
            for (int j = n-1-col_off-1; j >= col_off; --j) {
                output.push_back(matrix[m-1-row_off][j]);
            }
            for (int i = m-1-row_off-1; i > row_off; --i) {
                output.push_back(matrix[i][col_off]);
            }
        } else if (m - 2*row_off < 2) { // Row vector.
            for (int j = col_off; j < n - col_off; ++j) {
                output.push_back(matrix[row_off][j]);
            }
        } else { // Column vector.
            for (int i = row_off; i < m - row_off; ++i) {
                output.push_back(matrix[i][n-1-col_off]);
            }
        }
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return vector<int>();
        
        int m = matrix.size(), n = matrix[0].size();
        int max_offset = min((m-1)/2, (n-1)/2);
        
        vector<int> output;
        for (int i = 0; i <= max_offset; ++i) {
            helper(matrix, i, i, output);
        }
        
        return output;
    }
};
