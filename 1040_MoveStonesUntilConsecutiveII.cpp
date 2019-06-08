class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        
        // There are two cases that could lead to maximum number of moves. First, we can 
        // move the leftmost stone to the first valid empty position on the left. This takes 
        // 1 move (initial step). 
        // Then in the consequence steps, the positions for the leftmost stones are moved
        // 1 in each step. When it finishes, the leftmost stone is at (stones[n-1] - n + 1), and 
        // it takes (stones[n-1] - n + 1 - stones[1]) in the consequence steps, in addition to 
        // the initial step. Similar for the second case where we start from the rightmost stone.
        int upper = max(stones[n-1] - n + 1 - stones[1] + 1, stones[n-2] - stones[0] -n + 2);
        
        int lower = n; // Minimum number of moves.
        for (int i = 0, j = 0; j < n; ++j) {
            while (stones[j] - stones[i] + 1 > n) {
                // The window is larger then needed to contain n stones.
                ++i;
            }
            
            if (j - i + 1 == n-1 && stones[j] - stones[i] + 1 == n-1) {
                // Special case when there are n-1 consecutive stones in this window, need 2 moves.
                lower = min(lower, 2);
            } else {
                // There are less than (n-1) stones, the number of moves needed 
                // is equal to the number of stones not belonging to this window.
                lower = min(lower, n - (j - i + 1));
            }
        }
        
        return {lower, upper};
    }
};
