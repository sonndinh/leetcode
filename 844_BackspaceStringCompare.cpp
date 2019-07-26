class Solution {
public:
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
    
    bool backspaceCompare(string S, string T) {
        return convert(S) == convert(T);
    }
};
