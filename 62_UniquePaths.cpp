class Solution {
private: 
    vector<vector<int>> table;
    
public:
    int helper(int x, int y, int m, int n) {
        if (x == m - 1 && y == n - 1) // Reach target.
            return 1;
        
        if (table[x][y] != -1)
            return table[x][y];
        
        int down_count = 0, right_count = 0;
        if (x < m-1) {
            down_count = helper(x + 1, y, m, n);
        }
        if (y < n-1) {
            right_count = helper(x, y + 1, m, n);
        }
        table[x][y] = down_count + right_count;
        
        return table[x][y];
    }
    
    int uniquePaths(int m, int n) {
        table.resize(m, vector<int>(n, -1));
        
        return helper(0, 0, m, n);
    }
    
    // Brute force. Time O(2^n).
    int helper1(int x, int y, int m, int n) {
        if (x == m - 1 && y == n - 1) // Reach target.
            return 1;
        
        int down_count = 0, right_count = 0;
        if (x < m-1) {
            down_count = helper(x + 1, y, m, n);
        }
        if (y < n-1) {
            right_count = helper(x, y + 1, m, n);
        }
        
        return down_count + right_count;
    }
    
    int uniquePaths1(int m, int n) {
        return helper(0, 0, m, n);
    }
};
