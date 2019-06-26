class Solution {
private:
    void paren(vector<string>& v, string s, int open, int close, int n) {
        if (open == n && close == n) {
            v.push_back(s);
            return;
        }
        
        if (open == close) {
            paren(v, s + "(", open + 1, close, n);
        } else if (open == n) { // open > close
            paren(v, s + ")", open, close + 1, n);
        } else { // close < open < n
            paren(v, s + "(", open + 1, close, n);
            paren(v, s + ")", open, close + 1, n);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        paren(ret, "", 0, 0, n);
        return ret;
    }
};
