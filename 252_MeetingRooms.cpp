class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // Sort the intervals in increasing order of start times.
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] < b[0];
        });
        
        int max_end = numeric_limits<int>::min();
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] < max_end)
                return false;
            max_end = intervals[i][1];
        }
        return true;
    }
};
