class Solution {
    struct SegmentTree {
        // Each node in the tree contains the index of the bar with minimum of height 
        // within the range represented by the corresponding node.
        vector<int> tree;
        const vector<int>& input;
        
        // Recursively build the segment tree. 
        // @input: the input array for which we are building the segment tree.
        // @left: left index of the range in the input array.
        // @right: right index of the range in the input array.
        // @ idx: index of the correponding node in the segment tree.
        void build(int left, int right, int idx) {
            if (left == right) {
                tree[idx] = left;
            } else {
                int mid = left + (right - left)/2;
                build(left, mid, 2 * idx); // Build left child.
                build(mid+1, right, 2 * idx + 1); // Build right child.
                tree[idx] = input[tree[2*idx]] < input[tree[2*idx+1]]? tree[2*idx] : tree[2*idx+1];
            }
        }
        
        // Constructor.
        SegmentTree(const vector<int>& heights) : input(heights) {
            tree.resize(4 * input.size());
            build(0, (int)input.size()-1, 1);
        }
        
        // Query the index of shortest bar for the bars within a given range.
        // @idx: index of the node in the segment tree.
        // @tl, @tr: left and right indexes of elements represented by this node.
        // @left, @right: left and right indexes of the query range.
        int min_query(int idx, int tl, int tr, int left, int right) const {
            if (left > right) {
                return -1;
            }
            
            if (left == tl && right == tr) {
                // Query range coincide with the node's segment.
                return tree[idx];
            }
            
            // Compute ranges for the children nodes.
            int tm = tl + (tr - tl)/2;
            int left_idx = min_query(2*idx, tl, tm, left, min(tm, right));
            int right_idx = min_query(2*idx+1, tm+1, tr, max(tm+1, left), right);
            if (left_idx == -1)
                return right_idx;
            if (right_idx == -1)
                return left_idx;
            return input[left_idx] < input[right_idx]? left_idx : right_idx;
        }
    };
	
public:
    // Compute the maximum block from a given range of bars.
    int helper(vector<int>& heights, int left, int right, const SegmentTree& tree) {
        if (left > right)
            return 0;
        if (left == right)
            return heights[left];
        
        // Find the index of the shortest bar.
        int idx = tree.min_query(1, 0, (int)heights.size()-1, left, right);
        
        int max_left = helper(heights, left, idx - 1, tree);
        int max_right = helper(heights, idx + 1, right, tree);
        int max_cross = heights[idx] * (right - left + 1);
        
        return max(max_left, max(max_right, max_cross));
    }
    
    // Divide and conquer using segment tree.
    // Time O(nlgn). Space O(n) for the segment tree.
    int largestRectangleArea4(vector<int>& heights) {
        if (heights.empty())
            return 0;
        SegmentTree tree(heights);
        return helper(heights, 0, (int)heights.size()-1, tree);
    }
	
    // Recursive function for the divide and conquer method.
    int dac_helper(vector<int>& heights, int left, int right) {
        //cout << "left: " << left << ", right: " << right << endl;
        if (left > right)
            return 0;
        if (left == right)
            return heights[left];
        
        // Find the shortest bar.
        int lowest_idx = left, lowest = heights[left];
        for (int i = left+1; i <= right; ++i) {
            if (heights[i] < lowest) {
                lowest = heights[i];
                lowest_idx = i;
            }
        }
        
        // Split the range around the lowest bar.
        int max_left = dac_helper(heights, left, lowest_idx-1);
        int max_right = dac_helper(heights, lowest_idx+1, right);
        
        // Maximum area of the block with smallest height.
        int max_cross = lowest * (right - left + 1);
        return max(max_left, max(max_right, max_cross));
    }
    
    // Divide and conquer. Expected time O(nlgn), worst case time O(n^2).
    int largestRectangleArea3(vector<int>& heights) {
        return dac_helper(heights, 0, (int)heights.size()-1);
    }
	
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
