class Solution {
public:
    int numJewelsInStones(string J, string S) {
        char jewels_lcase[26] = {}, jewels_ucase[26] = {};
        
        for (char c : J) {
            if (c >= 'a') {
                jewels_lcase[c - 'a'] = 1;
            } else {
                jewels_ucase[c - 'A'] = 1;
            }
        }
        
        int count = 0;
        for (char c : S) {
            if (c >= 'a') {
                if (jewels_lcase[c - 'a'] == 1)
                    ++count;
            } else if (jewels_ucase[c - 'A'] == 1) {
                ++count;
            }
        }
        
        return count;     
    }
};
