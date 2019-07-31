class Solution {
public:
    struct TreeNode {
        // Each node of the tree contains a sorted list of nums.
        vector<int> vals;
    };
    
    struct SegmentTree {
        const vector<int>& input;
        // First node starts from index 1.
        vector<TreeNode> tree;
        
        // Build the segment tree.
        // @node_id: ID of the node in the tree.
        // @start and @end: range of the indexes of the numbers associated with this node.
        // Note that even though the number of nodes in this tree is (2n-1), it is not 
        // a complete tree. So we need to reserve more than 2n slots. 4n is enough.
        void build(int node_id, int start, int end) {
            if (start == end) {
                // Node for a single value.
                tree[node_id].vals.push_back(input[start]);
            } else {
                int mid = start + (end - start)/2;
                build(2*node_id, start, mid);
                build(2*node_id + 1, mid+1, end);
                
                // Merge the two sorted half.
                int left_size = tree[2*node_id].vals.size();
                int right_size = tree[2*node_id+1].vals.size();
                tree[node_id].vals.resize(left_size + right_size);
                int k = 0; // Write index of the current node.
                for (int i = 0, j = 0; i < left_size || j < right_size; ++k) {
                    if (i == left_size) {
                        tree[node_id].vals[k] = tree[2*node_id+1].vals[j];
                        ++j;
                    } else if (j == right_size) {
                        tree[node_id].vals[k] = tree[2*node_id].vals[i];
                        ++i;
                    } else {
                        if (tree[2*node_id].vals[i] < tree[2*node_id+1].vals[j]) {
                            tree[node_id].vals[k] = tree[2*node_id].vals[i];
                            ++i;
                        } else {
                            tree[node_id].vals[k] = tree[2*node_id+1].vals[j];
                            ++j;
                        }
                    }
                }
            }
        }

        // Init parameters and construct the tree.
        SegmentTree(const vector<int>& nums) : input{nums} {
            tree.resize(4 * nums.size());
            build(1, 0, (int)nums.size() - 1);
        }
        
        // Return the number of elements less than a given number.
        int bsearch(const vector<int>& vals, int num) {
            int left = 0, right = vals.size()-1;
            
            while (left <= right) {
                int mid = left + (right - left)/2;
                if (vals[mid] == num) {
                    if (mid > left && vals[mid-1] == num) {
                        right = mid - 1;
                    } else {
                        return mid;
                    }
                } else if (vals[mid] > num) {
                    right = mid - 1;
                } else if (vals[mid] < num) {
                    left = mid + 1;
                }
            }
            return left;
        }
        
        // Return the number of smaller elements to the right.
        int query(int id, int start, int end, int num, int l, int r) {
            if (l > r)
                return 0;
            if (r < start || end < l) {
                return 0;
            }
            if (start == l && end == r) {
                return bsearch(tree[id].vals, num);
            }
            
            int mid = start + (end - start)/2;
            return query(2*id, start, mid, num, l, min(r, mid)) + 
                query(2*id+1, mid+1, end, num, max(l, mid+1), r);
        }
    };
    
    // Use segment tree. Time O(n(lgn)^2), space O(nlgn).
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return vector<int>();
        
        SegmentTree seg_tree(nums);
        vector<int> ret(nums.size());
        
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            ret[i] = seg_tree.query(1, 0, nums.size()-1, nums[i], i+1, nums.size()-1);
        }
        
        return ret;
    }
    
    // Naive O(n^2) time, constant time.
    vector<int> countSmaller1(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i] > nums[j])
                    ++ret[i];
            }
        }
        
        return ret;
    }
};
