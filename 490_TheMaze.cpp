class Solution {
public:
    void compute_neighbors_helper(const vector<vector<int>>& maze, unordered_map<int, vector<pair<int,int>>>& neighbors, int i, int j) {
        int m = maze.size(), n = maze[0].size();
        if (neighbors.find(i * n + j) != neighbors.cend()) 
            return;
        
        int left = j-1; // Neighbor on left.
        while (left >= 0 && maze[i][left] != 1) {
            --left;
        }
        if (left + 1 != j) {
            neighbors[i * n + j].push_back({i, left + 1});
        }
                    
        int right = j + 1; // Neighbor on right.
        while (right < n && maze[i][right] != 1) {
            ++right;
        }
        if (right - 1 != j) {
            neighbors[i * n + j].push_back({i, right - 1});
        }
                    
        int up = i - 1; // Neighbor on top.
        while (up >= 0 && maze[up][j] != 1) {
            --up;
        }
        if (up + 1 != i) {
            neighbors[i * n + j].push_back({up + 1, j});
        }
                    
        int down = i + 1; // Neighbor on bottom.
        while (down < m && maze[down][j] != 1) {
            ++down;
        }
        if (down - 1 != i) {
            neighbors[i * n + j].push_back({down - 1, j});
        }
    }
    
    void compute_neighbors(const vector<vector<int>>& maze, unordered_map<int, vector<pair<int,int>>>& neighbors, vector<int> start) {
        int m = maze.size(), n = maze[0].size();
        vector<pair<int, int>> adj = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (maze[i][j] == 1)
                    continue;
                // The ball can stay in this cell if at least 1 of its side faces a wall.
                bool reachable = false;
                for (auto p : adj) {
                    int x = i + p.first, y = j + p.second;
                    if ((x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 1) || 
                       x == -1 || x == m || y == -1 || y == n) {
                        reachable = true;
                        break;
                    }
                }
                
                if (reachable) { // Compute cells that can be reached from this cell.
                    compute_neighbors_helper(maze, neighbors, i, j);
                }
            }
        }
        
        // Compute neighbors for start cell.
        if (neighbors.find(start[0] * n + start[1]) == neighbors.cend())
            compute_neighbors_helper(maze, neighbors, start[0], start[1]);
    }
    
    void print_neighbors(const unordered_map<int, vector<pair<int,int>>> neighbors, int n) {
        for (auto& neigh : neighbors) {
            cout << "Neighbors of (" << neigh.first/n << "," << neigh.first % n << "): ";
            for (auto& p : neigh.second) {
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << endl;
        }
    }
    
    bool dfs(const vector<vector<int>>& maze, unordered_map<int, vector<pair<int,int>>> neighbors, pair<int,int> curr, pair<int,int> dest, unordered_set<int>& visited) {
        if (curr.first == dest.first && curr.second == dest.second)
            return true;
        
        int m = maze.size(), n = maze[0].size();
        visited.insert(curr.first * n + curr.second);
        compute_neighbors_helper(maze, neighbors, curr.first, curr.second);
        const vector<pair<int,int>>& adj = neighbors.at(curr.first * n + curr.second);
        
        for (const pair<int,int>& p : adj) {
            if (visited.find(p.first * n + p.second) == visited.cend()) {
                if (dfs(maze, neighbors, p, dest, visited))
                    return true;
            }
        }
        
        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        unordered_map<int, vector<pair<int,int>>> neighbors;
        unordered_set<int> visited;

        //return dfs(maze, neighbors, {start[0], start[1]}, {destination[0], destination[1]}, visited);
        
        // BFS.
        queue<pair<int,int>> frontier;
        frontier.push({start[0], start[1]});
        visited.insert(start[0] * n + start[1]);
        
        while (!frontier.empty()) {
            pair<int,int> curr = frontier.front();
            frontier.pop();
            if (curr.first == destination[0] && curr.second == destination[1])
                return true;
            
            compute_neighbors_helper(maze, neighbors, curr.first, curr.second);
            const vector<pair<int,int>>& adj = neighbors[curr.first * n + curr.second];
            for (const pair<int,int>& p : adj) {
                if (visited.find(p.first * n + p.second) == visited.cend()) {
                    frontier.push(p);
                    visited.insert(p.first * n + p.second);
                }
            }
        }
        
        return false;
    }
};
