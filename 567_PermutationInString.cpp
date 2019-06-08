class Solution {
public:
    bool equal(const int a[26], const int b[26]) {
        for (int i = 0; i < 26; ++i) {
            if (a[i] != b[i]) 
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) 
            return false;
        
        int count1[26] {};
        for (int i = 0; i < s1.size(); ++i) {
            ++count1[s1[i] - 'a'];
        }
        
        int count2[26] = {};
        int left = 0;
        for (int right = 0; right < s2.size(); ++right) {
            ++count2[s2[right] - 'a'];
            if (right - left + 1 == s1.size()) {
                if (equal(count1, count2)) 
                    return true;
                else {
                    --count2[s2[left++] - 'a'];
                }
            } else if (right -left + 1 > s1.size()) {
                --count2[s2[left++] - 'a'];
            }
        }
        
        return false;
    }
};
