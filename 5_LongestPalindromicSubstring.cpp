class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        int max_length = 0;
        int max_left = -1, max_right = -1;
        
        // Entry (i,j) indicates whether s[i:(i+j)] is palindromic.
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                if (i + j < n) {
                    if (s[i] == s[i+j])
                        dp[i][i + j] = i == i + j? true : dp[i + 1][i + j - 1];
                    else 
                        dp[i][i + j] = false;
                    
                    if (dp[i][i + j] && (j + 1 > max_length)) {
                        max_length = j + 1;
                        max_left = i;
                        max_right = i + j;
                    }
                }
            }
        }
        
        if (max_length > 0) {
            return s.substr(max_left, max_length);
        }
        return "";
    }
};
