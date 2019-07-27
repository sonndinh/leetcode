class Solution {
public:
    // Time O(n), space O(1).
    int maxDistToClosest(vector<int>& seats) {
        int left = -1, right = 0;
        int max_dist = 0;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 1) {
                left = i;
            } else {
                if (i >= right) {
                    right = i;
                    while (right < seats.size() && seats[right] == 0)
                        ++right;
                }
                if (i == 0)
                    max_dist = right - i;
                else
                    max_dist = right == seats.size()? max(max_dist, i - left) : max(max_dist, min(i - left, right - i));
            }
        }
        
        return max_dist;
    }
	
    // Time O(n), space O(n).
    int maxDistToClosest1(vector<int>& seats) {
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
