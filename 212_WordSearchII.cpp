class Solution {
private:
    struct TrieNode {
        bool is_word;
        string word;
        TrieNode* children[26];
        TrieNode() : is_word{false}, word{}, children{} {}
    };
    
    struct Trie {
        TrieNode *root;
        
        Trie() : root(new TrieNode) {}
        ~Trie() {
            destructor_helper(root);
        }
        
        void destructor_helper(TrieNode* curr) {
            for (int i = 0; i < 26; ++i) {
                if (curr->children[i])
                    destructor_helper(curr->children[i]);
            }
            delete curr;
        }
        
        void insert(string word) {
            // Insert a word.
            TrieNode *curr = root;
            for (int i = 0; i < word.size(); ++i) {
                char c = word[i];
                if (!curr->children[c - 'a']) {
                    curr->children[c - 'a'] = new TrieNode;
                }
                curr = curr->children[c - 'a'];
            }
            curr->is_word = true;
            curr->word = word;
        }
        
        // Return false if key is not in trie OR cannot delete a node.
        bool remove_helper(string word, TrieNode* curr, int i) {
            if (i == word.size() - 1) {
                if (!curr->is_word) return false; // Key not in trie.
                delete curr;
                return true;
            }
            
            // Go down further the word.
            char c = word[i+1];
            if (!curr->children[c - 'a']) return false; // Key not in trie.
            if (!remove_helper(word, curr->children[c - 'a'], i+1))
                return false;
            
            // Up here, the above subtrie has been removed successfully.
            curr->children[c - 'a'] = nullptr;
            if (curr == root)
                return true;
            
            // Delete this node if it does not have any children anymore.
            bool done = true;
            for (int i = 0; i < 26; ++i) {
                if (curr->children[i]) {
                    done = false;
                    break;
                }
            }
            if (done) {
                delete curr;
                return true;
            }
            return false;
        }

        // Remove a key in the trie. NOTE: do not really need to remove.
        void remove(string word) {
            if (word.empty()) return;
            remove_helper(word, root, -1);
        }
        
        bool search(string word) {
            // Return whether a word is stored in trie.
            TrieNode *curr = root;
            for (int i = 0; i < word.size(); ++i) {
                char c = word[i];
                if (!curr->children[c - 'a'])
                    return false;
                curr = curr->children[c - 'a'];
            }
            return curr->is_word;
        }
    };
    
public:
    void visit(const vector<vector<char>>& board, TrieNode *node, int i, int j, 
               vector<vector<bool>>& visited, unordered_set<string>& ret) {
        int m = board.size(), n = board[0].size();
        char c = board[i][j];
        if (!node->children[c - 'a'])
            return;
        if (node->children[c - 'a']->is_word)
            ret.insert(node->children[c - 'a']->word);
        
        vector<pair<int,int>> adj{{-1,0}, {1,0}, {0,-1}, {0,1}};
        visited[i][j] = true;
        for (auto p : adj) {
            int x = i + p.first, y = j + p.second;
            if ((x >= 0 && x < m) && (y >= 0 && y < n) && !visited[x][y]) {
                visit(board, node->children[c - 'a'], x, y, visited, ret);
            }
        }
        visited[i][j] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || words.empty())
            return vector<string>();
        
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }
        
        TrieNode *root = trie.root;
        int m = board.size(), n = board[0].size();
        // Track the visited cells.
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Store found words in a set to avoid duplicates.
        unordered_set<string> ret;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visit(board, root, i, j, visited, ret);
            }
        }

        return vector<string>(ret.begin(), ret.end());
    }
};
