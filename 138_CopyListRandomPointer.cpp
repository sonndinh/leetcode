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
