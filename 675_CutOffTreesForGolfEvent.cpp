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
    
    // Use normal BFS.
    int cutOffTree1(vector<vector<int>>& forest) {
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
    
    struct Compare {
        bool operator()(const tuple<int,int,int>& a, const tuple<int,int,int>& b) const {
            return get<2>(a) < get<2>(b);
        }
    };
    
    int helper_bidirect_bfs(const vector<vector<int>>& board, queue<tuple<int,int,int>>& fringe, 
                            unordered_map<int, int>& visited, const unordered_map<int, int>& other_visited) {
        int m = board.size(), n = board[0].size();
        auto cell = fringe.front();
        fringe.pop();
        int key = get<0>(cell) * n + get<1>(cell);
        int curr_dist = visited[key];
        if (other_visited.find(key) != other_visited.cend()) {
            return visited[key] + other_visited.at(key);
        }
         
        vector<pair<int, int>> adj{{-1,0}, {1,0}, {0,-1}, {0,1}};
        for (auto p : adj) {
            int x = get<0>(cell) + p.first, y = get<1>(cell) + p.second;
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != 0 && 
                visited.find(x*n + y) == visited.cend()) {
                fringe.push({x, y, board[x][y]});
                visited.insert({x*n + y, curr_dist + 1});
            }
        }
        
        return -1;
    }
    
    // Use bidirectional BFS to find distance between 2 trees.
    int bidirect_bfs(const vector<vector<int>>& board, const tuple<int,int,int>& s, const tuple<int,int,int>& t) {
        int m = board.size(), n = board[0].size();
        queue<tuple<int,int,int>> fringe_s, fringe_t;
        unordered_map<int, int> visited_s, visited_t;
        fringe_s.push(s);
        fringe_t.push(t);
        // Map from visited cells to their distances.
        visited_s.insert({get<0>(s) * n + get<1>(s), 0});
        visited_t.insert({get<0>(t) * n + get<1>(t), 0});
        
        int dist = -1;
        while (!fringe_s.empty() && !fringe_t.empty()) {
            int ret = helper_bidirect_bfs(board, fringe_s, visited_s, visited_t);
            if (ret != -1) {
                dist = ret;
                break;
            }
            
            ret = helper_bidirect_bfs(board, fringe_t, visited_t, visited_s);
            if (ret != -1) {
                dist = ret;
                break;
            }
        }
        if (dist == -1)
            return -1;
        
        // Find the shortest distance from intersection of two visited sets.
        for (auto p : visited_s) {
            int x = p.first / n, y = p.first % n;
            if (visited_t.find(p.first) != visited_t.cend()) {
                dist = min(dist, p.second + visited_t[p.first]);
            }
        }
        return dist;
    }
    
    vector<tuple<int,int,int>> get_heights(const vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<tuple<int, int, int>> heights;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    heights.push_back({i, j, forest[i][j]});
                }
            }
        }
        if (forest[0][0] == 0 || forest[0][0] == 1)
            heights.push_back({0, 0, forest[0][0]});
        sort(heights.begin(), heights.end(), Compare());
        return heights;
    }
    
    struct AstarCompare {
        bool operator() (const vector<int>& a, const vector<int>& b) const {
            return a[2] > b[2]; // Compare total cost f = g + h.
        }
    };
    
    int astar(const vector<vector<int>>& board, const tuple<int,int,int>& s, const tuple<int,int,int>& t) {
        int m = board.size(), n = board[0].size();
        priority_queue<vector<int>, vector<vector<int>>, AstarCompare> min_heap;
        unordered_map<int, int> node_to_cost; // Map from tree to total cost (not real cost).
        min_heap.push({get<0>(s), get<1>(s), 0, 0});
        node_to_cost.insert({get<0>(s) * n + get<1>(s), 0});
        
        vector<pair<int, int>> adj{{-1,0}, {1,0}, {0,-1}, {0,1}};
        while (!min_heap.empty()) {
            auto cell = min_heap.top();
            min_heap.pop();
            if (cell[0] == get<0>(t) && cell[1] == get<1>(t)) {
                // Found the target.
                return cell[3];
            }
            
            for (auto p : adj) {
                int x = cell[0] + p.first, y = cell[1] + p.second;
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != 0) {
                    // Relax distance to (x,y): f(x,y) = g(x,y) + h(x,y).
                    int g_dist = cell[3] + 1;
                    int h_dist = abs(x - get<0>(t)) + abs(y - get<1>(t));
                    if (node_to_cost.find(x * n + y) == node_to_cost.cend() || 
                       g_dist + h_dist < node_to_cost[x * n + y]) {
                        min_heap.push({x, y, g_dist + h_dist, g_dist});
                        node_to_cost[x*n + y] = g_dist + h_dist;
                    }
                }
            }
        }
        
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty()) return 0;

        // Each tuple contains coordinate (x,y) and corresponding heights.
        vector<tuple<int, int, int>> heights = get_heights(forest);
        
        // May need to walk from (0, 0) to the cell with shortest tree first
        // since we always cut trees in increasing heights.
        int dist = 0;
        if (forest[0][0] > get<2>(heights[0])) {
            //int ret = bidirect_bfs(forest, {0, 0, forest[0][0]}, heights[0]);
            int ret = astar(forest, {0, 0, forest[0][0]}, heights[0]);
            if (ret == -1)
                return -1;
            dist += ret;
        }
            
        for (int i = 0; i < heights.size()-1; ++i) {
            //int ret = bidirect_bfs(forest, heights[i], heights[i+1]);
            int ret = astar(forest, heights[i], heights[i+1]);
            if (ret == -1)
                return -1;
            dist += ret;
        }
        return dist;
    }
};
