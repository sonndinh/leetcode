class Solution {
public:
    char next_char(string S, int& i) {
        char c = '0';
        int count_bs = 0;
        while (i >= 0) {
            if (S[i] == '#') {
                ++count_bs;
                --i;
            } else if (count_bs > 0) {
                --count_bs;
                --i;
            } else {
                c = S[i];
                --i;
                break;
            }
        }
        return c;
    }
    
    bool backspaceCompare(string S, string T) {
        // Iterate backward.
        int i = S.size() - 1, j = T.size() - 1;
        while (i >= 0 || j >= 0) {
            char first = next_char(S, i);
            char second = next_char(T, j);
            if ((first != '0' && second != '0' && first != second) || (first != '0' && second == '0') ||
               (first == '0' && second != '0'))
                return false;
        }
        return true;
    }
    
    // Return the next final character starting from index i.
    // Assume that character at index i is a lowercase.
    char next_char2(string S, int& i) {
        char c = '0';
        while (i < S.size()) {
            if ((i + 1 < S.size() && S[i+1] != '#') || i + 1 == S.size()) {
                c = S[i];
                ++i;
                break;
            } else {
                ++i;
                while (i < S.size() && S[i] == '#')
                    ++i;
            }
        }
        
        return c;
    }
    
    // Linear time, constant space.
    bool backspaceCompare2(string S, string T) {
        int i = 0, j = 0;
        // Ignore leading #s for the two strings.
        while (i < S.size() && S[i] == '#')
            ++i;
        while (j < T.size() && T[j] == '#')
            ++j;
        
        while (i < S.size() || j < T.size()) {
            char first = next_char(S, i); cout << first;
            char second = next_char(T, j); cout << " " << second << endl;
            if ((first != '0' && second != '0' && first != second) || (first != '0' && second == '0') ||
               (first == '0' && second != '0'))
                return false;
        }
        return true;
    }
    
    
    string convert(string S) {
        stack<char> stk;
        for (char c : S) {
            if (c == '#') {
                if (!stk.empty())
                    stk.pop();
            } else {
                stk.push(c);
            }
        }
        
        int size = stk.size();
        string str_s(size, ' ');
        for (int i = size-1; i >= 0; --i) {
            str_s[i] = stk.top();
            stk.pop();
        }
        return str_s;
    }
    
    // Linear time, linear space.
    bool backspaceCompare1(string S, string T) {
        return convert(S) == convert(T);
    }
};
