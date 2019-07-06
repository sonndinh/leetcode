class Solution {
public:
    // Based on a discussion on leetcode forum.
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int n = prices.size();
        vector<int> s0(n, 0), s1(n, 0), s2(n, 0);
        s0[0] = 0; // Hold no stock.
        s1[0] = -prices[0]; // Just buy a stock at day 0.
        s2[0] = numeric_limits<int>::min(); // Base case.
        
        for (int i = 1; i < n; ++i) {
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s0[i-1] - prices[i], s1[i-1]);
            s2[i] = s1[i-1] + prices[i];
        }
        
        return max(s0[n-1], s2[n-1]);
    }
};
