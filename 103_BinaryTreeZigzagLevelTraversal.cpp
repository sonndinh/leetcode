/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        
        deque<TreeNode*> deck;
        bool left_to_right = true;
        int count = 1; // Number of nodes in the current level.       
        deck.push_back(root);
        
        while (!deck.empty()) {
            int curr_count = 0;
            vector<int> curr_level;
            if (left_to_right) {
                // Read from left to right.
                while (count) {
                    TreeNode *node = deck.front();
                    deck.pop_front();
                    --count;
                    if (node)
                        curr_level.push_back(node->val);
                    
                    // Insert children nodes to the back. Push left child first.
                    if (node->left) {
                        deck.push_back(node->left);
                        ++curr_count;
                    }
                    if (node->right) {
                        deck.push_back(node->right);
                        ++curr_count;
                    }
                }
            } else {
                // Read from right to left.
                while (count) {
                    TreeNode *node = deck.back();
                    deck.pop_back();
                    --count;
                    if (node)
                        curr_level.push_back(node->val);
                    
                    // Insert children nodes to the front. Push right child first.
                    if (node->right) {
                        deck.push_front(node->right);
                        ++curr_count;
                    }
                    if (node->left) {
                        deck.push_front(node->left);
                        ++curr_count;
                    }
                }
            }
            
            ret.push_back(curr_level);
            left_to_right  = !left_to_right;
            count = curr_count;
        }
        
        return ret;
    }
};
