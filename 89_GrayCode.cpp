class Solution {
public:
    // Return the last number in the sequence.
    int visit(int curr_code, int pos, vector<int>& sequence) {
        if (pos == 1) {
            sequence.push_back(curr_code);
            // Flip the least-significant bit.
            curr_code ^= 1;
            sequence.push_back(curr_code);
            return curr_code;
        }
        
        curr_code = visit(curr_code, pos-1, sequence);
        // Flip the current bit (at position @pos).
        curr_code ^= (1 << (pos - 1));
        return visit(curr_code, pos-1, sequence);
    }
    
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        
        int code = 0;
        vector<int> sequence;
        
        visit(code, n, sequence);
        return sequence;
    }
};
