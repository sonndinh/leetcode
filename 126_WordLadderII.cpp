class Solution {
private:
    void build_adj_list(vector<string>& wordList, vector<vector<int>>& adj_list) {
        int n = wordList.size();
        for (int i = 0; i < n-1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string& word1 = wordList[i];
                string& word2 = wordList[j];
                int count_diff = 0;
                for (int k = 0; k < word1.size(); ++k) {
                    if (word1[k] != word2[k]) {
                        ++count_diff;
                        if (count_diff > 1)
                            break;
                    }
                }
                
                if (count_diff <= 1) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
    }
    
    void compute_shortest_distances(const vector<vector<int>>& adj_list, unordered_map<int, int>& shortest_dists) {
        int n = adj_list.size();
        queue<pair<int, int>> q; // Each pair contains word id and its distance.
        unordered_set<int> visited;
        q.push({n-1, 1});
        visited.insert(n-1);
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            shortest_dists[p.first] = p.second;
            
            const vector<int>& adj = adj_list[p.first];
            for (int id : adj) {
                if (visited.find(id) == visited.end()) {
                    q.push({id, p.second + 1});
                    visited.insert(id);
                }
            }
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> paths;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return paths;
        
        wordList.emplace_back(beginWord);
        int n = wordList.size();
        
        // Construct adjacency list for the word graph.
        vector<vector<int>> adj_list(n);
        build_adj_list(wordList, adj_list);
        
        // Run BFS to find shortest distances from beginWord to every other words.
        unordered_map<int, int> shortest_dists;
        compute_shortest_distances(adj_list, shortest_dists);

        // Index of the endWord.
        int end_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (wordList[i] == endWord) {
                end_idx = i;
                break;
            }
        }
        
        // Find all shortest paths to endWord.
        vector<vector<int>> paths_idx;
        //queue<pair<int, vector<string>>> que;
        queue<pair<int, vector<int>>> que;
        //que.push({n-1, {wordList[n-1]}});
        que.push({n-1, {n-1}});
        while (!que.empty()) {
            //pair<int, vector<string>> p = que.front();
            pair<int, vector<int>> p = que.front();
            que.pop();
            //if (wordList[p.first] == endWord) {
            if (p.first == end_idx) {
                //paths.emplace_back(p.second);
                paths_idx.emplace_back(p.second);
                continue;
            }
            
            int curr_dist = p.second.size();
            
            vector<int>& adj = adj_list[p.first];
            for (int id : adj) {
                if (curr_dist + 1 == shortest_dists[id]) {
                    //pair<int, vector<string>> temp;
                    pair<int, vector<int>> temp;
                    temp.first = id;
                    temp.second = p.second;
                    //temp.second.push_back(wordList[id]);
                    temp.second.push_back(id);
                    que.emplace(temp);
                }
            }
        }
        
        // Reconstruct paths of strings from indexes.
        for (vector<int>& p : paths_idx) {
            vector<string> path(p.size());
            for (int i = 0; i < p.size(); ++i) {
                path[i] = wordList[p[i]];
            }
            paths.emplace_back(path);
        }
                 
        return paths;
    }
};
