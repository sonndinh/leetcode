class Solution {
public:
    void reverse(string& s, int l, int r) {
        for (int i = l, j = r; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
    
    string reverseWords(string s) {
        int n = s.size();
        reverse(s, 0, n-1);
        
        // Remove spaces.
        int start = 0, end = n - 1;
        while (s[start] == ' ') ++start;
        while (s[end] == ' ') --end;
        
        int write_idx = start;
        for (int i = start; i <= end; ) {
            if (s[i] == ' ') {
                s[write_idx] = s[i];
                ++write_idx;
                ++i;
                while (i <= end && s[i] == ' ')
                    ++i;
            } else {
                s[write_idx] = s[i];
                ++write_idx;
                ++i;
            }
        }
        end = write_idx - 1;
        
        // Invert individual word.
        int i = start, l = start, r = end;
        while (i <= end) {
            while (i <= end && s[i] != ' ') {
                ++i;
            }
            r = i - 1;
            reverse(s, l, r);
            l = i + 1;
            ++i;
        }
        
        return s.substr(start, end - start + 1);
    }
};
