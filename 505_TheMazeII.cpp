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
    
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return a[2] > b[2];
        }
    };
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        unordered_map<int, vector<pair<int,int>>> neighbors;
            
        // Each vector<int> contains coordinate of the cell and its distance from start.
        priority_queue<vector<int>, vector<vector<int>>, Compare> frontier;
        unordered_map<int, int> visited;
        frontier.push({start[0], start[1], 0});
        visited.insert({start[0] * n + start[1], 0});
        
        while (!frontier.empty()) {
            auto curr = frontier.top();
            frontier.pop();
            if (curr[0] == destination[0] && curr[1] == destination[1]) {
                return curr[2];
            }
            
            compute_neighbors_helper(maze, neighbors, curr[0], curr[1]);
            const vector<pair<int,int>>& adj = neighbors[curr[0] * n + curr[1]];
            
            for (pair<int,int> p : adj) {
                int dist = curr[2] + abs(p.first - curr[0]) + abs(p.second - curr[1]);
                if (visited.find(p.first * n + p.second) == visited.cend() || 
                    visited[p.first * n + p.second] > dist) {
                    frontier.push({p.first, p.second, dist});
                    visited[p.first * n + p.second] = dist;
                }
            }
        }
        
        return -1;
    }
};
