class Solution {
public:
    void reverse(vector<char>& s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
    
    void reverseWords(vector<char>& s) {
        reverse(s, 0, s.size()-1);
        
        int i = 0, left = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                reverse(s, left, i-1);
                left = i+1;
            }
            ++i;
        }
        reverse(s, left, i-1);
    }
};
