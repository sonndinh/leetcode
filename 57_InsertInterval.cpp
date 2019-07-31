class Solution {
public:
	// Linear time.
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        
        vector<int> temp = newInterval;
        for (int i = 0; i < intervals.size(); ++i) {
            vector<int>& curr_interval = intervals[i];
            if (curr_interval[1] >= temp[0]) {
                if (temp[1] < curr_interval[0]) {
                    ret.push_back(temp);
                    ret.insert(ret.end(), intervals.begin() + i, intervals.end());
                    return ret;
                } else {
                    // Merge these intervals.
                    temp[0] = min(temp[0], curr_interval[0]);
                    temp[1] = max(temp[1], curr_interval[1]);
                }
            } else {
                ret.push_back(curr_interval);
            }
        }
        if (ret.empty() || temp[0] > ret.back()[1])
            ret.push_back(temp);
        
        return ret;
    }
};
