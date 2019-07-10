class Solution {
public:
    bool is_cyclic(int id, const vector<vector<int>>& adj_list, unordered_set<int>& traversed, unordered_set<int>& visited) {
        if (visited.find(id) != visited.cend()) 
            return false;
        
        traversed.insert(id);
        visited.insert(id);
        for (int adj : adj_list[id]) {
            if (!is_cyclic(adj, adj_list, traversed, visited))
                return false;
        }
        visited.erase(id);
        return true;
    }
    
    void dfs(int i, vector<vector<int>>& adj_list, unordered_set<int>& visited, list<int>& courses) {
        visited.insert(i);
        for (int adj : adj_list[i]) {
            if (visited.find(adj) == visited.cend()) 
                dfs(adj, adj_list, visited, courses);
        }
        courses.push_front(i);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Construct adjacency list for the graph.
        vector<vector<int>> adj_list(numCourses);
        for (auto& vec : prerequisites) {
            adj_list[vec[1]].push_back(vec[0]);
        }
        
        // Use DFS to detect cycle.
        unordered_set<int> traversed, visited;
        for (int i = 0; i < numCourses; ++i) {
            if (traversed.find(i) == traversed.cend() && !is_cyclic(i, adj_list, traversed, visited))
                return vector<int>();
        }
        
        // Topological sort to compute list of courses.
        list<int> courses;
        visited.clear();
        for (int i = 0; i < numCourses; ++i) {
            if (visited.find(i) == visited.cend())
                dfs(i, adj_list, visited, courses);
        }

        return vector<int>(courses.begin(), courses.end());        
    }
};
