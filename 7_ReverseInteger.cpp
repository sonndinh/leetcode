class Solution {
public:
    int reverse(int x) {
        long long int temp = 0;
        vector<int> digits;
        
        long long int val = abs((long long int)x);
        while (val > 0) {
            digits.push_back(val % 10);
            val /= 10;
        }
        
        // Ignore trailing zeros.
        int i = 0;
        while (i < digits.size() && digits[i] == 0) {
            ++i;
        }
        
        for (; i < digits.size(); ++i) {
            temp += digits[i] * pow(10, digits.size() - i - 1);
            if ((x >= 0 && temp > numeric_limits<int>::max()) || (x < 0 && -temp < numeric_limits<int>::min()))
                return 0;
        }
        
        return x < 0 ? -temp : temp;
    }
};
