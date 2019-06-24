class Solution {
private:
    struct Compare {
        bool operator() (const pair<string, int>& a, const pair<string, int>& b) const {
            return a.second < b.second;
        }
    };
        
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_words;
        for (string& word : banned) {
            banned_words.insert(word);
        }
        
        unordered_map<string, int> count;
        string token;
        stringstream ss(paragraph);
        while (ss >> token) {
            // Convert to lowercase.
            for (int i = 0; i < token.size(); ++i) {
                token[i] = tolower(token[i]);
            }
            
            // Remove punctuation.
            size_t punc = token.find_first_of("!?',;.");
            while (punc != string::npos) {
                // Ignore banned words.
                if (banned_words.count(token.substr(0, punc)) == 0) {
                    count[token.substr(0, punc)]++;
                }
                
                token = token.substr(punc+1);
                punc = token.find_first_of("!?',;.");
            }
            
            if (!token.empty() && banned_words.count(token) == 0) {
                count[token]++;
            }
        }
        
        string ret;
        int max_occur = 0;
        for (auto& p : count) {
            if (p.second > max_occur) {
                max_occur = p.second;
                ret = p.first;
            }
        }
        return ret;
    }
};
