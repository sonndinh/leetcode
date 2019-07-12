class Solution {
    unordered_set<string> islands;
    unordered_set<int> visited;
    
public:
    void dfs(const vector<vector<int>>& grid, int i, int j, int id, string& code) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1 &&
           visited.find(i * grid[0].size() + j) == visited.cend()) {
            visited.insert(i * grid[0].size() + j);
            code += to_string(id);
            dfs(grid, i, j-1, 1, code); // left
            dfs(grid, i, j+1, 2, code); // right
            dfs(grid, i-1, j, 3, code); // up
            dfs(grid, i+1, j, 4, code); // down
            code += to_string(id);
        }
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j++) {
                if (visited.find(i * n + j) == visited.cend() && grid[i][j] == 1) {
                    string code;
                    dfs(grid, i, j, 0, code);
                    islands.insert(code);
                }
            }
        }
        
        return islands.size();
    }
};
