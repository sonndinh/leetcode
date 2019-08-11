class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // Temperature runs in range [30, 100].
        vector<list<int>> table(71);
        table[T.back()-30].push_front((int)T.size() - 1);
        vector<int> ret(T.size(), 0);
        
        // Going through the days in the input from the end to start.
        for (int i = (int)T.size()-2; i >= 0; --i) {
            int temp = T[i];
            // Index of the nearest day in array T that has higher temperature.
            int min_idx = T.size();
            for (int j = temp + 1; j <= 100; ++j) {
                int idx = j - 30;
                if (!table[idx].empty() && table[idx].front() > i) {
                    min_idx = min(min_idx, table[idx].front());
                }
            }
            if (min_idx < T.size()) {
                ret[i] = min_idx - i;
            }
            table[temp - 30].push_front(i);
        }
        
        return ret;
    }
};
