class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int max_length = 0, curr_length = 0;
        
        // Set of distinct characters in the current substring.
        unordered_set<char> distinct_chars;
        
        while (left <= right && right < s.size()) {
            if (distinct_chars.count(s[right]) == 0) {
                distinct_chars.insert(s[right++]);
                ++curr_length;
            } else {
                max_length = max(max_length, curr_length);
                
                while (s[left] != s[right]) {
                    distinct_chars.erase(s[left]);
                    ++left;
                    --curr_length;
                }
                ++left;
                ++right;
            }
        }
        max_length = max(max_length, curr_length);
        
        return max_length;
    }
};
