class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        
        for (int i = n-1; i >= 0; --i) {
            int length = n - i;
            if (dict.count(s.substr(i)) > 0) {
                dp[i] = true;
            } else {
                for (int j = 1; j <= length; ++j) {
                    if (dict.count(s.substr(i, j)) > 0 && dp[i+j]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};
