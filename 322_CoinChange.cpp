class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount+1, -1);
        count[0] = 0;
        
        for (int i = 1; i <= amount; ++i) {
            int num_coins = numeric_limits<int>::max();
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i && count[i - coins[j]] >= 0) {
                    num_coins = min(num_coins, 1 + count[i - coins[j]]);
                }
            }
            if (num_coins < numeric_limits<int>::max())
                count[i] = num_coins;
        }
        
        return count[amount];
    }
};
