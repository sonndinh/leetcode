class Solution {
public:
    struct Compare {
        bool operator() (const pair<string, int>& a, const pair<string, int>& b) const {
            if (a.second < b.second)
                return true;
            else if (a.second == b.second && a.first.compare(b.first) > 0) 
                return true;
            
            return false;
        }
    };
    
    struct MinCompare {
        bool operator() (const pair<string, int>& a, const pair<string, int>& b) const {
            if (a.second > b.second)
                return true;
            else if (a.second == b.second && a.first.compare(b.first) < 0)
                return true;
            return false;
        }
    };
    
    // O(nlgk) time, O(n) space.
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (string word : words) {
            count[word]++;
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, MinCompare> queue;
        for (auto p : count) {
            if (queue.size() == k && 
                (queue.top().second < p.second || 
                 (queue.top().second == p.second && queue.top().first.compare(p.first) > 0))) {
                queue.pop();
                queue.push(p);
            } else if (queue.size() < k) {
                queue.push(p);
            }
        }
        
        vector<string> ret(queue.size());
        int idx = queue.size() - 1;
        while (!queue.empty()) {
            ret[idx--] = queue.top().first;
            queue.pop();
        }
        return ret;
    }
    
    // O(klgn) time, O(n) space.
    vector<string> topKFrequent1(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (string word : words) {
            count[word]++;
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> queue(count.begin(), count.end());
        vector<string> ret;
        while (k-- > 0 && !queue.empty()) {
            ret.push_back(queue.top().first);
            queue.pop();
        }
        
        return ret;
    }
};
