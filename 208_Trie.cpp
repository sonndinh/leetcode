class Trie {
    class TrieNode {
        public:
        TrieNode() : is_word{false}, children{nullptr} {}
        
        bool is_word;
        TrieNode* children[26];
    };
    
private:
    TrieNode *root;
        
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode;
            }
            curr = curr->children[c - 'a'];
        }
        curr->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); ++i) {
            char c = prefix[i];
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
