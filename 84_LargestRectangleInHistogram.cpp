class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
    }
    
    // Brute force. Time O(n^2).
    int largestRectangleArea1(vector<int>& heights) {
        int area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int running_min = heights[i];
            for (int j = i; j < heights.size(); ++j) {
                running_min = min(running_min, heights[j]);
                area = max(area, running_min * (j - i + 1));
            }
        }
        
        return area;
    }
};
