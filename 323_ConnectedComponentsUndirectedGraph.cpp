class Solution {
    vector<vector<int>> adj_list;
    unordered_set<int> visited;
    
public:
    void dfs(int i) {
        visited.insert(i);
        vector<int>& adj = adj_list[i];
        for (int j : adj) {
            if (visited.find(j) == visited.cend()) {
                dfs(j);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        adj_list.resize(n);
        for (vector<int>& e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (visited.find(i) == visited.end()) {
                dfs(i);
                ++ret;
            }
        }
        
        return ret;
    }
};
