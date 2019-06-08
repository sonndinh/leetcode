class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty()) 
            return 0;
        
        int count[26] = {};
        int left = 0;
        int max_occur = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            max_occur = max(max_occur, ++count[s[right] - 'A']);
            if (max_occur + k < right - left + 1) {
                // Need to advance left pointer.
                --count[s[left++] - 'A'];
            }
        }
        
        return s.size() - left;
    }
};
