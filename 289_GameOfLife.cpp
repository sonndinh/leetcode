class Solution {
public:
    // In-place update.
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        int m = board.size(), n = board[0].size();
        queue<pair<int,int>> frontier;
        unordered_map<int, int> orig_vals;
        frontier.push({0,0});
        orig_vals[0] = board[0][0];
        
        vector<pair<int,int>> adj{{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {1,1}, {-1,1}, {1,-1}};
        while (!frontier.empty()) {
            auto curr = frontier.front();
            int i = curr.first, j = curr.second;
            frontier.pop();
            int num_live = 0;
            for (auto p : adj) {
                int x = i + p.first, y = j + p.second;
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (orig_vals.find(x * n + y) != orig_vals.cend()) {
                        num_live = orig_vals[x * n + y] == 1? num_live + 1 : num_live;
                    } else {
                        if (board[x][y] == 1) {
                            ++num_live;
                        }
                        orig_vals[x * n + y] = board[x][y];
                        frontier.push({x, y});
                    }
                }
            }
            
            if (board[i][j] == 1 && num_live < 2)
                board[i][j] = 0;
            else if (board[i][j] == 1 && (num_live == 2 || num_live == 3))
                board[i][j] = 1;
            else if (board[i][j] == 1 && num_live > 3)
                board[i][j] = 0;
            else if (board[i][j] == 0 && num_live == 3)
                board[i][j] = 1;
        }
    }
	
    void gameOfLife1(vector<vector<int>>& board) {
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
