class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return (a.second < b.second);
        }
    };

	// Time complexity: O(n + klgn), where n is the number of numbers.
	// Space: O(n).
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            ++count[nums[i]];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> max_heap(count.begin(), count.end());
        vector<int> ret(k);
        for (int i = 0; i < k; ++i) {
            ret[i] = max_heap.top().first;
            max_heap.pop();
        }
        
        return ret;
    }
};
