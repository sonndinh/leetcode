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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> frontier;
        frontier.push({root, 1});
        
        int width = 1;
        int count = 1;
        unsigned long long left = 0, right = 0;
        int next_count = 0;
        while (!frontier.empty()) {
            TreeNode *node = frontier.front().first;
            unsigned long long pos = frontier.front().second;
            frontier.pop();
            
            if (left == 0) left = pos;
            
            if (node->left) {
                frontier.push({node->left, pos*2});
                ++next_count;
            }
            if (node->right) {
                frontier.push({node->right, pos*2 + 1});
                ++next_count;
            }
            
            --count;
            if (count == 0) {
                width = max((unsigned long long)width, pos - left + 1);
                left = 0;
                count = next_count;
                next_count = 0;
            }
        }
        
        return width;
    }
	
    int widthOfBinaryTree1(TreeNode* root) {
        if (!root) 
            return 0;
        
        deque<TreeNode*> frontier;
        unordered_set<TreeNode*> visited;
        frontier.push_back(root);
        visited.insert(root);

        int max_width = 1; 
        int count = 1; // Number of entries in the previous level.
        int next_count = 0;
        bool inserting = false;
        while (!frontier.empty()) {
            TreeNode *node = frontier.front();
            frontier.pop_front();
            if (!node) {
                if (inserting) {
                    frontier.push_back(nullptr);
                    frontier.push_back(nullptr);
                    next_count += 2;
                }
            } else {
                if (node->left || inserting) {
                    frontier.push_back(node->left);
                    ++next_count;
                    inserting = node->left? true : inserting;
                }
                if (node->right || inserting) {
                    frontier.push_back(node->right);
                    ++next_count;
                    inserting = node->right? true : inserting;
                }
            }
            
            --count;
            if (count == 0) {
                // Remove the null nodes from the back.
                while (!frontier.empty() && frontier.back() == nullptr) {
                    frontier.pop_back();
                    --next_count;
                }
                
                // Reset bookkeeping variables.
                max_width = max(max_width, next_count);
                count = next_count;
                next_count = 0;
                inserting = false;
            }
        }
        
        return max_width;
    }
};
