class Solution {
public:
    int firstUniqChar(string s) {
        // Number of occurrences and index of the first occurrence.
        vector<pair<int, int>> occur(26, {0, -1});
  
        for (int i = 0; i < s.size(); ++i) {
            ++occur[s[i] - 'a'].first;
            if (occur[s[i] - 'a'].first == 1) {
                occur[s[i] - 'a'].second = i;
            }
        }
        
        int ret = -1;
        for (pair<int, int>& p : occur) {
            if (p.first == 1) {
                if (ret == -1 || (ret >= 0 && ret > p.second)) {
                    ret = p.second;
                }
            }
        }

        return ret;
    }
};
