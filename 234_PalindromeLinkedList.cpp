/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // O(1) space.
    bool isPalindrome(ListNode *head) {
        ListNode *curr = head;
        int n = 0;
        while (curr) {
            ++n;
            curr = curr->next;
        }
        
        if (n <= 1) return true;
        
        int steps;
        if (n % 2 == 0)
            steps = n/2;
        else 
            steps = n/2 + 1;
        
        curr = head;
        while (steps > 0) {
            curr = curr->next;
            --steps;
        }
        
        // Reverse the second half.
        ListNode *head2 = curr;
        ListNode *next = head2->next;
        while (next) {
            curr->next = next->next;
            next->next = head2;
            head2 = next;
            next = curr->next;
        }
        
        // Check palindrome.
        while (head2) {
            if (head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
    
    
    // O(n) space.
    bool isPalindrome2(ListNode* head) {
        vector<int> arr;
        ListNode *curr = head;
        while (curr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        int n = arr.size();
        for (int i = 0; i < n/2; ++i) {
            if (arr[i] != arr[n-1-i])
                return false;
        }
        return true;
    }
};
