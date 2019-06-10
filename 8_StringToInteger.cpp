class Solution {
public:
    int myAtoi(string str) {
        int val = 0;
        int size = str.size();
        char sign = '+';

        int i = 0;
        while (str[i] == ' ')
            ++i;
        
        if (str[i] != '-' && str[i] != '+' && !(str[i] >= '0' && str[i] <= '9'))
            return val;
        
        if (str[i] == '-') 
            sign = '-';
        
        if (str[i] == '-' || str[i] == '+')
            ++i;
        
        int j = i;
        // Get the last decimal digit.
        while (j < size && str[j] >= '0' && str[j] <= '9') {
            ++j;
        }
        
        
        int temp = 0;
        int k = j - 1;
        int power = 0;
        while (k >= i) {
            int digit = str[k] - '0';
            val += digit * pow(10, (j - 1) - k);
            
            if (temp > val) { // Overflow.
                if (sign == '+')
                    return INT_MAX;
                else 
                    return INT_MIN;
            } 
                
            --k;
            temp = val;
        }
        
        if (sign == '+') {
            return val;
        } else {
            return -val;
        }
    }
};
