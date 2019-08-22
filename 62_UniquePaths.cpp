class Solution {
private: 
    vector<vector<int>> table;
    
public:
    // Bottom up. Time O(nm), space O(n).
    int uniquePaths(int m, int n) {
        // Only need 1 row.
        vector<int> dp(n, 1);
        
        // Compute from left to right.
        for (int i = m-2; i >= 0; --i) {
            for (int j = n-2; j >= 0; --j) {
                dp[j] = dp[j] + dp[j+1];
            }
        }
        
        return dp[0];
    }
    
    
    int helper2(int x, int y, int m, int n) {
        if (x == m - 1 && y == n - 1) // Reach target.
            return 1;
        
        if (table[x][y] != -1)
            return table[x][y];
        
        int down_count = 0, right_count = 0;
        if (x < m-1) {
            down_count = helper2(x + 1, y, m, n);
        }
        if (y < n-1) {
            right_count = helper2(x, y + 1, m, n);
        }
        table[x][y] = down_count + right_count;
        
        return table[x][y];
    }
    
    // Top-down with memoization. Time O(nm), space O(nm).
    int uniquePaths2(int m, int n) {
        table.resize(m, vector<int>(n, -1));
        return helper2(0, 0, m, n);
    }
    
    // Brute force. Time O(2^max(n, m)).
    int helper1(int x, int y, int m, int n) {
        if (x == m - 1 && y == n - 1) // Reach target.
            return 1;
        
        int down_count = 0, right_count = 0;
        if (x < m-1) {
            down_count = helper1(x + 1, y, m, n);
        }
        if (y < n-1) {
            right_count = helper1(x, y + 1, m, n);
        }
        
        return down_count + right_count;
    }
    
    int uniquePaths1(int m, int n) {
        return helper1(0, 0, m, n);
    }
};
