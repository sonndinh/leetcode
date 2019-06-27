class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> frontier;
        unordered_set<string> visited;
        frontier.push({sr, sc});
        visited.insert(to_string(sr) + "_" + to_string(sc));
        int oldColor = image[sr][sc];
        
        int m = image.size(), n = image[0].size();
        while (!frontier.empty()) {
            pair<int, int> p = frontier.front();
            frontier.pop();
            image[p.first][p.second] = newColor;
            
            vector<pair<int, int>> adj{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto& t : adj) {
                int x = p.first + t.first, y = p.second + t.second;
                if (x >= 0 && x < m && y >= 0 && y < n && 
                    image[x][y] == oldColor && visited.count(to_string(x) + "_" + to_string(y)) == 0) {
                    frontier.push({x, y});
                    visited.insert(to_string(x) + "_" + to_string(y));
                }
            }
        }
        
        return image;
    }
};
