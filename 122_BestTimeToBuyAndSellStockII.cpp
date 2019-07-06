class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i = 0;
        while (i < prices.size()) {
            int buy_day = -1;
            while (i+1 < prices.size() && prices[i] >= prices[i+1]) {
                ++i;
            }
            if (i+1 < prices.size()) {
                buy_day = i++;
            }
            if (buy_day < 0) 
                break;
            
            int sell_day;
            while (i + 1 < prices.size() && prices[i] <= prices[i+1]) {
                ++i;
            }
            sell_day = i++;
            profit += prices[sell_day] - prices[buy_day];
        }
        
        return profit;
    }
};
