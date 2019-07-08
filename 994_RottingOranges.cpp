class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> frontier;
        unordered_set<int> visited;
        int max_dist = 0;
        
        int num_oranges = 0;
        int m = grid.size(), n = grid[0].size();
        // Find all rotten oranges.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    frontier.push({i, j, 0});
                    visited.insert(i * n + j);
                }
                if (grid[i][j] > 0)
                    ++num_oranges;
            }
        }
        
        vector<pair<int,int>> adj{{-1,0}, {1,0}, {0,-1}, {0,1}};
        while (!frontier.empty()) {
            vector<int> curr = frontier.front();
            frontier.pop();
            if (curr[2] > max_dist) max_dist = curr[2];
            
            for (auto& p : adj) {
                int x = p.first + curr[0], y = p.second + curr[1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0 && visited.find(x * n + y) == visited.cend()) {
                    frontier.push({x, y, curr[2] + 1});
                    visited.insert(x * n + y);
                }
            }
        }
            
        return visited.size() == num_oranges? max_dist : -1;
    }
};
