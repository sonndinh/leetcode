class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        
        for (int i = 1; i <= n; ++i) {
            bool multiple_threes = i % 3 == 0 ? true : false;
            bool multiple_fives = i % 5 == 0 ? true : false;
            if (multiple_threes && !multiple_fives) {
                ret[i-1] = "Fizz";
            } else if (!multiple_threes && multiple_fives) {
                ret[i-1] = "Buzz";
            } else if (multiple_threes && multiple_fives) {
                ret[i-1] = "FizzBuzz";
            } else {
                ret[i-1] = to_string(i);
            }
        }
        return ret;
    }
};
