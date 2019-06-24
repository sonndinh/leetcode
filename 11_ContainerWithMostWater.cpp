class Solution {
public:
    int maxArea(vector<int>& height) {
        int cap = 0, n = height.size();
        
        for (int i = 0, j = n-1; i < j;) {
            int temp = (j - i) * min(height[i], height[j]);
            if (temp > cap) {
                cap = temp;
            }
            
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        
        return cap;
    }
};
