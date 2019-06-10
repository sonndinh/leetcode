class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Dimension.
        int n = matrix.size();
        
        // Rotate layer-by-layer.
        for (int i = 0; i < n/2; ++i) {
            // Upper column indexes for the current layer.
            int upper = n - 1 - i;
            for (int j = i; j < upper; ++j) {
                int temp = matrix[i][j];
                swap(matrix[j][upper], temp);
                swap(matrix[upper][i + upper - j], temp);
                swap(matrix[i + upper -j][i], temp);
                swap(matrix[i][j], temp);
            }
        }
    }
};
