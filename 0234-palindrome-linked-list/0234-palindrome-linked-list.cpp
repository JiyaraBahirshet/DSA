class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* current = head;
        
        while (current != NULL) {
            ListNode* nextNode = current->next;
            
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        
        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2. Reverse second half
        ListNode* secondHalf = reverseList(slow->next);
        
        // 3. Compare both halves
        ListNode* firstHalf = head;
        
        while (secondHalf != NULL) {
            
            if (firstHalf->val != secondHalf->val) {
                return false;
            }
            
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
    }
};