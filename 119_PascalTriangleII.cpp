class Solution {
public:
    vector<int> getRow(int rowIndex) {
        list<int> temp;
        
        for (int i = 0; i <= rowIndex; ++i) {
            if (i == 0) {
                temp.push_back(1);
            } else if (i == 1) {
                temp.push_back(1);
            } else {
                list<int>::iterator it = temp.begin();
                ++it;
                int prev = 1;
                for (; it != temp.end(); ++it) {
                    int curr = *it;
                    *it = curr + prev;
                    prev = curr;
                }
                temp.push_back(1);
            }
        }
        
        return vector<int>{temp.begin(), temp.end()};
    }
};
