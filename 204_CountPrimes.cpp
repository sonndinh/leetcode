class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        // True indicates a prime.
        vector<bool> arr(n, true);
            
        for (int i = 2; i < n; ++i) {
            if (arr[i] == true) {
                ++count;
                int k = i;
                while (k + i < n) {
                    k += i;
                    arr[k] = false;
                }
            }
        }
        
        return count;
    }
};
