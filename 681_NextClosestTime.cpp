class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> input{time[0]-'0', time[1]-'0', time[3]-'0', time[4]-'0'};
        vector<int> digits = input;
        sort(digits.begin(), digits.end()); // Sorted in increasing order.
        int hour = stoi(time.substr(0, 2));
        
        // See if we can find a larger number for the second digit of the minute part.
        for (int i = 0; i < 4; ++i) {
            if (digits[i] > input[3]) {
                string output = time;
                output[4] = digits[i] + '0';
                return output;
            }
        }
        
        // The first digit of the minute part.
        for (int i = 0; i < 4; ++i) {
            if (digits[i] > input[2] && digits[i] < 6) {
                string output = time;
                output[3] = digits[i] + '0';
                // Pick the smallest value for last digit.
                output[4] = digits[0] + '0';
                return output;
            }
        }
        
        // The second digit of the hour part.
        for (int i = 0; i < 4; ++i) {
            if ((input[0] < 2 && digits[i] > input[1]) || 
                (input[0] == 2 && digits[i] > input[1] && digits[i] <= 4)) {
                string output = time;
                output[1] = digits[i] + '0';
                output[3] = digits[0] + '0';
                output[4] = digits[0] + '0';
                return output;
            }
        }
        
        // The first digit of the hour part.
        for (int i = 0; i < 4; ++i) {
            if (input[0] == 2) {
                break;
            } else if (digits[i] > input[0] && digits[i] <= 2) {
                string output = time;
                output[0] = digits[i];
                output[1] = digits[0] + '0';
                output[3] = digits[0] + '0';
                output[4] = digits[0] + '0';
                return output;
            }
        }
        
        // Not found a closest time in the same day. Find a closest one in the next day.
        string output(5, digits[0] + '0');
        output[2] = ':';
        return output;
    }
};
