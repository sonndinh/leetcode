#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<int>> my_map;
        // Length of each word.
        int n = beginWord.size();
        // Number of words in the list.
        int m = wordList.size();
        wordList.push_back(beginWord);
        
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                string tmp = wordList[i];
                tmp[j] = '*';
                my_map[tmp].emplace_back(i);
            }
        }
        
        // Construct adjacency list.
        vector<vector<int>> adj_list(m+1);
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                string tmp = wordList[i];
                tmp[j] = '*';
                for (int k = 0; k < my_map[tmp].size(); ++k) {
                    if (my_map[tmp][k] != i) {
                        adj_list[i].emplace_back(my_map[tmp][k]);
                    }
                }
            }
        }
            
        // Run BFS to find shortest path from beginWord to endWord.
        queue<int> kueue;
        kueue.push(m);
        unordered_set<int> visited;
		visited.insert(m);		
        vector<int> dist(m+1);
        dist[m] = 1;

		int end_idx = -1;
        while (!kueue.empty()) {
            int idx = kueue.front();
            kueue.pop();
            if (wordList[idx] == endWord) {
				end_idx = idx;
				break;
			}
            
            for (int i = 0; i < adj_list[idx].size(); ++i) {
                int next = adj_list[idx][i];
                if (visited.count(next) == 0) {
                    kueue.push(next);
                    dist[next] = dist[idx] + 1;
					visited.insert(next);
				}
            }
        }
		if (end_idx == -1) {
			return 0;
		}
        
        return dist[end_idx];
    }

int main() {
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> list = {"hot", "dot", "dog", "lot", "log", "cog"};
	//vector<string> list = {"hot", "dot", "dog", "lot", "log"};
	Solution sol;
	int ret = sol.ladderLength(beginWord, endWord, list);
	cout << "Length: " << ret << endl;
	return 0;
}
