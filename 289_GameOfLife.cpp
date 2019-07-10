class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        // Use a new array. Space O(mn), time O(mn).
        vector<vector<int>> state(m, vector<int>(n));
        
        vector<pair<int,int>> adj{{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {1,1}, {-1,1}, {1,-1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int num_live = 0;
                for (pair<int,int> p : adj) {
                    int x = i + p.first, y = j + p.second;
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1)
                        ++num_live;
                }
                if (board[i][j] == 1 && num_live < 2)
                    state[i][j] = 0;
                else if (board[i][j] == 1 && (num_live == 2 || num_live == 3))
                    state[i][j] = 1;
                else if (board[i][j] == 1 && num_live > 3)
                    state[i][j] = 0;
                else if (board[i][j] == 0 && num_live == 3)
                    state[i][j] = 1;
            }
        }
        
        board = state;
    }
};
