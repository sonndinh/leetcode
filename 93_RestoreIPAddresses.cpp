class Solution {
public:
    void get_ips(string s, int i, vector<string>& ret, string curr, int k) {
        if (k == 0) {
            if (s.size() - i > 3 || (s.size() - i > 1 && s[i] == '0'))
                return;
            
            int val = stoi(s.substr(i));
            if (val >= 0 && val <= 255) {
                ret.push_back(curr + "." + s.substr(i));
                return;
            }
        }
        
        string updated_str;
        if (i + 1 < s.size()) {
            updated_str = curr.empty() ? s.substr(i, 1) : curr + "." + s[i];
            get_ips(s, i + 1, ret, updated_str, k-1);
        }
        if (i + 2 < s.size() && s[i] != '0') {
            updated_str = curr.empty()? s.substr(i, 2) : curr + "." + s.substr(i, 2);
            get_ips(s, i + 2, ret, updated_str, k-1);
        }
        
        if (i + 3 < s.size() && s[i] != '0') {
            int val = stoi(s.substr(i, 3));
            if (val >= 1 && val <= 255) {
                updated_str = curr.empty()? s.substr(i, 3) : curr + "." + s.substr(i, 3);
                get_ips(s, i + 3, ret, updated_str, k-1);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        get_ips(s, 0, ret, "", 3);
        return ret;
    }
};
