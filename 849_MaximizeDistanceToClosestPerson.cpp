class Solution {
public:
    // Time O(n), space O(n).
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> dist(n);
        
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                dist[i] = 0;
                tmp = 0;
            } else {
                if (i == 0) {
                    dist[i] = numeric_limits<int>::max();
                } else {
                    dist[i] = ++tmp;
                }
            }
        }
        
        tmp = 0;
        int max_dist = 0;
        for (int i = n-1; i >= 0; --i) {
            if (seats[i] == 0) {
                ++tmp;
                if (i < n-1) {
                    dist[i] = min(tmp, dist[i]);
                }
                if (max_dist < dist[i])
                    max_dist = dist[i];
            } else {
                tmp = 0;
            }
        }
        
        return max_dist;
    }
};
