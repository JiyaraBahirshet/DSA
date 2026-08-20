class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Empty list or only one node
        if (head == NULL || head->next == NULL)
            return head;

        // Find length and tail
        int n = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            n++;
        }

        // Reduce unnecessary rotations
        k = k % n;

        // No rotation needed
        if (k == 0)
            return head;

        // Make the list circular
        tail->next = head;

        // Find the new tail
        int steps = n - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // New head comes after new tail
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;
    }
};