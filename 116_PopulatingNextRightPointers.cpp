/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    void connect_left_right(Node *left, Node* right) {
        while (left) {
            left->next = right;
            left = left->right;
            right = right->left;
        }
    }
    
    void helper(Node *left, Node *right) {
        if (!left || !right)
            return;
        
       if (!left->left && !left->right && !right->left && !right->right) {
           left->next = right;
           return;
        }
        
        helper(left->left, left->right);
        helper(right->left, right->right);
        connect_left_right(left, right);
    }
    
    Node* connect(Node* root) {
        if (!root) return root;
        
        helper(root->left, root->right);
        Node *curr = root;
        while (curr) {
            curr->next = nullptr;
            curr = curr->right;
        }
        
        return root;
    }
};
