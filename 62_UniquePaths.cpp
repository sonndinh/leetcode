class Solution {
public:
    int helper(int x, int y, int m, int n) {
        if (x == m - 1 && y == n - 1) 
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
    
    int uniquePaths(int m, int n) {
        return helper(0, 0, m, n);
    }
};
