class Solution {
public:
    // Dynamic programming. Time (likely) O(n), space O(n).
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        
        int n = heights.size();
        // Indexes of shorter bars to the left and right.
        vector<int> on_left(n), on_right(n);
        on_left[0] = -1;
        on_right[n-1] = n;
        int max_area = 0;
        
        // Compute on_left array. This loop likely takes O(n) time.
        for (int i = 1; i < n; ++i) {
            int t = i - 1;
            while (t >= 0 && heights[t] >= heights[i]) {
                t = on_left[t];
            }
            on_left[i] = t;
        }
        
        // Compute on_right array;
        for (int i = n-2; i >= 0; --i) {
            int t = i + 1; 
            while (t < n && heights[t] >= heights[i]) {
                t = on_right[t];
            }
            on_right[i] = t;
        }
        
        // For each bar, compute the area of block with height equal to its height.
        for (int i = 0; i < n; ++i) {
            int area = heights[i] * (on_right[i] - on_left[i] - 1);
            max_area = max(max_area, area);
        }
        
        return max_area;
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
