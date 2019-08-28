class Solution {
public:
    void sanity_check(const vector<int>& temp, int N) {
        // Verify if the returned array is correct.
        assert(temp.size() == N);
        for (int i = 0; i < N-2; ++i) {
            for (int j = i + 2; j < N; ++j) {
                int sum = temp[i] + temp[j];
                for (int k = i + 1; k < j; ++k) {
                    if (sum == 2 * temp[k]) {
                        cout << "Violate: temp[" << i  << "] = " << temp[i] 
                            << ", temp[" << j << "] = " << temp[j] 
                            << ", temp[" << k << "] = " << temp[k] << endl;
                    }
                }
            }
        }        
    }
    
    vector<int> beautifulArray(int N) {
        vector<int> temp{1};

        while (temp.size() < N) {
            // Create even array.
            vector<int> even(temp.size());
            for (int i = 0; i < temp.size(); ++i) {
                even[i] = 2*temp[i];
            }
            
            // Create odd array.
            for (int i = 0; i < temp.size(); ++i) {
                temp[i] = 2*temp[i] - 1;
            }
            
            // Concatenate them together.
            temp.insert(temp.end(), even.begin(), even.end());
        }
        
        // Remove redundant elements.
        if (temp.size() > N) {
            int num_dels = temp.size() - N;
            vector<int>::iterator it = temp.begin();
            while (num_dels > 0) {
                if (*it > N) {
                    temp.erase(it);
                    --num_dels;
                } else {
                    ++it;
                }
            }
        }
        
        //sanity_check(temp, N);
        
        return temp;
    }
};
