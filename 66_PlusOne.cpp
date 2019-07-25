class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret(digits.size()+1);
        int carry = 1;
        
        for (int i = digits.size() - 1; i >= 0; --i) {
            int val = digits[i] + carry;
            ret[i+1] = val%10;
            carry = val/10;
        }
        if (carry > 0) 
            ret[0] = carry;
        else 
            ret.erase(ret.begin());
        
        return ret;
    }
};
