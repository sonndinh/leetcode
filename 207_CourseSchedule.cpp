class Solution {
private:
    bool visit(const vector<vector<int>>& graph, unordered_set<int>& visited, int curr) {
        if (visited.count(curr) > 0) {
            return false;
        }
        visited.insert(curr);
        
        if (graph[curr].empty()) {
            visited.erase(curr);
            return true;
        }
        
        for (int next : graph.at(curr)) {
            if (!visit(graph, visited, next))
                return false;
        }
        visited.erase(curr);
        return true;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (vector<int>& v : prerequisites) {
            graph[v[1]].push_back(v[0]);
        }
        
        // Set of nodes that have been considered.
        unordered_set<int> traversed;
        
        // Use DFS to traverse the dependency graph.
        unordered_set<int> visited;
        for (int i = 0; i < numCourses; ++i) {
            if (traversed.count(i) > 0)
                continue;
            
            if (!visit(graph, visited, i)) {
                return false;
            }
            traversed.insert(i);
        }
        
        return true;
    }
};
