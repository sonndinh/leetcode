class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> durations{1, 7, 30};
        vector<int> dp(days.size(), 0);
        
        for (int i = days.size() - 1; i >= 0; --i) {
            int cost = numeric_limits<int>::max();
            
            for (int j = 0; j < 3; ++j) {
                int duration = durations[j];
                int idx = i;
                while (idx < days.size() && days[idx] < days[i] + duration) {
                    ++idx;
                }
                if (idx == days.size()) {
                    cost = min(cost, costs[j]);
                } else {
                    cost = min(cost, costs[j] + dp[idx]);
                }
            }
            dp[i] = cost;
        }
        
        return dp[0];
    }
};
