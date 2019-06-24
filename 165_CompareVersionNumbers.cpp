class Solution {
public:
    vector<int> parse(string& version) {
        vector<int> num;
        int i = 0;
        while (i < version.size()) {
            int temp = 0; // Default value for this level.
            int start = -1;
            while (i < version.size() && version[i] != '.') {
                if (version[i] != '0' && start == -1) {
                    start = i;
                }
                ++i;
            }
            
            if (start != -1) {
                num.push_back(stoi(version.substr(start, i - start)));
            } else {
                num.push_back(temp);
            }
            ++i;
        }
        
        return num;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> num1, num2;
        num1 = parse(version1);
        num2 = parse(version2);
        
        int i = 0, j = 0;
        while (i < num1.size() && j < num2.size()) {
            if (num1[i] < num2[j]) {
                return -1;
            } else if (num1[i] > num2[j]) {
                return 1;
            } else {
                ++i;
                ++j;
            }
        }
        
        if (i < num1.size()) {
            while (i < num1.size()) {
                if (num1[i])
                    return 1;
                ++i;
            }
        } else if (j < num2.size()) {
            while (j < num2.size()) {
                if (num2[j])
                    return -1;
                ++j;
            }
        }
        
        return 0;
    }
};
