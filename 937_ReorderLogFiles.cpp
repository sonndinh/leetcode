class Solution {
private:
    struct Compare {
        // Compare two logs consisting of letters.
        bool operator()(const string& a, const string& b) const {
            int i = a.find_first_of(" ");
            int j = b.find_first_of(" ");
            string temp1 = a.substr(i+1), temp2 = b.substr(j+1);
            
            int val = temp1.compare(temp2);
            if (val < 0) {
                return true;
            } else if (val > 0) {
                return false;
            }
            
            // The contents are equal, compare identifiers.
            if (a.substr(0, i).compare(b.substr(0, j)) < 0)
                return true;
            else 
                return false;
        }
    };
    
    bool contains_digits(const string& s) {
        stringstream ss(s);
        string str;
        ss >> str; // Read identifier.
        ss >> str; // Read the first word.
        
        if (isdigit(str[0]))
            return true;
        return false;
    }
    
    int next(const vector<string>& logs, int curr) {
        while (curr >= 0 && contains_digits(logs[curr])) {
            --curr;
        }
        return curr;
    }
    
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [&](const string& a, const string& b) -> bool {
            int i = a.find_first_of(" "), j = b.find_first_of(" ");
            string ida = a.substr(0, i);
            string idb = b.substr(0, j);
            
            if (isalpha(a[i+1]) && isalpha(b[j+1])) {
                int ret = a.substr(i+1).compare(b.substr(j+1));
                if (ret < 0)
                    return true;
                else if (ret > 0)
                    return false;
                
                if (ida.compare(idb) < 0)
                    return true;
                else 
                    return false;
            } 
                
            return (isalpha(a[i+1]) ? true : (isalpha(b[j+1] ? false : true)));
        });
        
        return logs;
    }
    
    vector<string> reorderLogFiles1(vector<string>& logs) {
        if (logs.empty())
            return logs;
        
        // Move logs with numbers to the end.
        int j = next(logs, logs.size() - 1);
        int i = j - 1;
        
        for (; i >= 0;) {
            while (i >= 0 && !contains_digits(logs[i])) {
                --i;
            }
            if (i >= 0) {
                swap(logs[i], logs[j]);
                j = next(logs, j-1);
                --i;
            }
        }
        
        // Sort the logs with letters.
        sort(logs.begin(), logs.begin()+j+1, Compare());
        return logs;
    }
};
