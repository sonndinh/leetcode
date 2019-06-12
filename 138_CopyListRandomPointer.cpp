/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    // O(n) time, O(1) space.
    Node* copyRandomList(Node *head) {
        Node *curr = head;
        Node *ret = nullptr;
        
        // Create clone nodes.
        while (curr) {
            Node *clone = new Node(curr->val, nullptr, nullptr);
            if (!ret)
                ret = clone;
            
            Node *next = curr->next;
            curr->next = clone;
            clone->next = next;
            curr = next;
        }
        
        curr = head;
        // Set random pointers for the clone nodes.
        while (curr) {
            Node *clone = curr->next;
            if (curr->random)
                clone->random = curr->random->next;
            
            curr = curr->next->next;
        }
        
        curr = head;
        // Set the next pointers for the original and clone nodes.
        while (curr) {
            Node *clone = curr->next;
            curr->next = curr->next->next;
            curr = clone->next;
            
            if (clone->next)
                clone->next = clone->next->next;
        }
        
        return ret;
    }
	
    // O(n) space and time.
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old_to_new;
        Node *curr = head;
        Node *ret = nullptr; // Head of the copy.
        
        while (curr) {
            Node * clone = new Node(curr->val, nullptr, nullptr);
            old_to_new[curr] = clone;
            if (!ret)
                ret = clone;
            curr = curr->next;
        }
        
        curr = head;
        while (curr) {
            Node *clone = old_to_new[curr];
            if (curr->next)
                clone->next = old_to_new[curr->next];
            if (curr->random)
                clone->random = old_to_new[curr->random];
            curr = curr->next;
        }
        return ret;
    }
};
