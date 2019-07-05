class AutocompleteSystem {
private:
    struct TrieNode {
        TrieNode() : count{0}, children{}, parent{nullptr} {}
        
        string sentence;
        int count; // Number of times this sentences is searched.
        unordered_map<string, int> hot_sentences;
        TrieNode* children[27]; // Include single space character.
        TrieNode* parent;
    };
    
    struct Trie {
        struct Compare {
            bool operator() (const pair<string, int>& a, const pair<string, int>& b) const {
                return (a.second > b.second) || (a.second == b.second && a.first.compare(b.first) < 0);
            }
        };
        
        Trie() {
            root = new TrieNode();
            curr = nullptr;
        }
        
        // Insert a sentence a number of times.
        void insert(string key, int times) {
            curr = root;
            for (int i = 0; i < key.size(); ++i) {
                char c = key[i];
                int idx;
                if (c == ' ')
                    idx = 26;
                else 
                    idx = c - 'a';
                
                if (curr->children[idx] == nullptr) {
                    curr->children[idx] = new TrieNode();
                    curr->children[idx]->parent = curr;
                    curr->children[idx]->sentence = curr->sentence + c;
                }
                curr = curr->children[idx];
            }
            curr->sentence = key;
            curr->count = times - 1;
            update();
        }
        
        // Get hot sentences from the current node.
        vector<string> get_hot_sentences() {
            TrieNode *node = nullptr;
            if (!curr)
                node = root;
            else 
                node = curr;
            
            vector<pair<string, int>> freq(node->hot_sentences.begin(), node->hot_sentences.end());
            sort(freq.begin(), freq.end(), Compare());
            vector<string> ret;
            for (auto& p : freq) {
                ret.push_back(p.first);
            }
            
            return ret;
        }
        
        // Return 3 hottest sentences starting the current node and with a given input character.
        // Assume the input character can be lowercase letter or ' '.
        vector<string> search(char c) {
            int idx;
            if (c == ' ')
                idx = 26;
            else 
                idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
                curr->children[idx]->parent = curr;
                curr->children[idx]->sentence = curr->sentence + c;
                curr = curr->children[idx];
                return vector<string>();
            }
            
            curr = curr->children[idx];
            
            vector<pair<string, int>> freq(curr->hot_sentences.begin(), curr->hot_sentences.end());
            sort(freq.begin(), freq.end(), Compare());
            vector<string> ret;
            for (auto& p : freq) {
                ret.push_back(p.first);
            }
            
            return ret;
        }
        
        // Update the trie with new sentence inserted in the current node.
        void update() {
            curr->count++;
            
            TrieNode *temp = curr;
            int count = curr->count;
            string sentence = curr->sentence;
            while (temp) {
                if (temp->hot_sentences.size() < 3) {
                    temp->hot_sentences[sentence] = count;
                    temp = temp->parent;
                } else if (temp->hot_sentences.find(sentence) != temp->hot_sentences.cend()) {
                    temp->hot_sentences[sentence] = count;
                    temp = temp->parent;
                } else {
                    int min_count = numeric_limits<int>::max();
                    string str;
                    // Find smallest sentence with minimum count.
                    for (auto& p : temp->hot_sentences) {
                        if (p.second < min_count || (p.second == min_count && p.first.compare(str) > 0)) {
                            str = p.first;
                            min_count = p.second;
                        }
                    }
                    
                    if (min_count < count || (min_count == count && sentence.compare(str) < 0)) {
                        temp->hot_sentences.erase(str);
                        temp->hot_sentences.insert({sentence, count});
                        temp = temp->parent;
                    } else {
                        break;
                    }
                }
            }
            
            curr = root;
        }
        
        TrieNode *root;
        TrieNode *curr;
    };
    
    Trie trie;
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); ++i) {
            trie.insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            trie.update(); // Update the trie with the new sentence.
            return vector<string>();
        } else {
            return trie.search(c);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
