class Solution {
public:
    // Find shortest distance from cell (i,j) to a tree with height h.
    // Return tuple of x-coordinate, y-coordinate, distance to the target tree.
    tuple<int, int, int> bfs(const vector<vector<int>>& board, int i, int j, int h) {
        if (board[i][j] == h)
            return {i, j, 0};
        
        int m = board.size(), n = board[0].size();
        queue<tuple<int, int, int>> frontier;
        unordered_set<int> visited;
        frontier.push({i, j, 0});
        visited.insert(i * n + j);
        
        vector<pair<int,int>> adj{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int dist = 0;
        while (!frontier.empty()) {
            auto cell = frontier.front();
            frontier.pop();
            
            for (auto p : adj) {
                int x = get<0>(cell) + p.first, y = get<1>(cell) + p.second;
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != 0 && visited.count(x * n + y) == 0) {
                    if (board[x][y] == h) {
                        return {x, y, get<2>(cell) + 1};
                    }
                    
                    frontier.push({x, y, get<2>(cell) + 1});
                    visited.insert(x * n + y);
                }
            }
        }
        // Tree not found.
        return {-1, -1, -1};
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty()) return 0;
        if (forest[0][0] == 0) return -1;

        int m = forest.size(), n = forest[0].size();
        vector<int> heights;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] != 0) {
                    heights.push_back(forest[i][j]);
                }
            }
        }
        sort(heights.begin(), heights.end());
        
        int dist = 0;
        int i = 0, j = 0;
        for (int height : heights) {
            auto ret = bfs(forest, i, j, height);
            if (get<2>(ret) == -1)
                return -1;
            
            dist += get<2>(ret);
            i = get<0>(ret);
            j = get<1>(ret);
        }
        return dist;
    }
};
