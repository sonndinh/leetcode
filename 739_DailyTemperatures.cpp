class Solution {
public:
    // Time O(n), where n is the number of days. Space O(1) for the table.
    vector<int> dailyTemperatures(vector<int>& T) {
        // Store the closest day to the right that has higher temparature.
        vector<int> table(71, -1);
        table[T.back()-30] = (int)T.size() - 1;
        vector<int> ret(T.size(), 0);
        
        // Going through the days in the input from the end to start.
        for (int i = (int)T.size()-2; i >= 0; --i) {
            int temp = T[i];
            // Index of the nearest day in array T that has higher temperature.
            int min_idx = T.size();
            for (int j = temp + 1; j <= 100; ++j) {
                int idx = j - 30;
                if (table[idx] != -1) {
                    min_idx = min(min_idx, table[idx]);
                }
            }
            if (min_idx < T.size()) {
                ret[i] = min_idx - i;
            }
            
            // Update the newest day for this temparature.
            table[temp - 30] = i;
        }
        
        return ret;
    }
};
