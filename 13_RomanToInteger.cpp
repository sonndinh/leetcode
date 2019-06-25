class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int val = 0, i = 0;
        
        while (i < n) {
            switch (s[i]) {
                case 'I':
                    if (i < n-1 && s[i+1] == 'V') {
                        val += 4;
                        i += 2;
                    } else if (i < n-1 && s[i+1] == 'X') {
                        val += 9;
                        i += 2;
                    } else {
                        val += 1;
                        ++i;
                    }
                    break;
                case 'X':
                    if (i < n-1 && s[i+1] == 'L') {
                        val += 40;
                        i += 2;
                    } else if (i < n-1 && s[i+1] == 'C') {
                        val += 90;
                        i += 2;
                    } else {
                        val += 10;
                        ++i;
                    }
                    break;
                case 'C':
                    if (i < n-1 && s[i+1] == 'D') {
                        val += 400;
                        i += 2;
                    } else if (i < n-1 && s[i+1] == 'M') {
                        val += 900;
                        i += 2;
                    } else {
                        val += 100;
                        ++i;
                    }
                    break;
                case 'V':
                    val += 5;
                    ++i;
                    break;
                case 'L':
                    val += 50;
                    ++i;
                    break;
                case 'D':
                    val += 500;
                    ++i;
                    break;
                case 'M':
                    val += 1000;
                    ++i;
                    break;
                default:
                    cout << "Should never go here!" << endl;
            }
        }
        
        return val;
    }
};
