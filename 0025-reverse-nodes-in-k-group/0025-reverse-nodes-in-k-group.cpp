class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            // Step 1: Find kth node
            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth != NULL; i++) {
                kth = kth->next;
            }

            // Not enough nodes
            if (kth == NULL) {
                break;
            }

            // Step 2: Store the next group's starting node
            ListNode* groupNext = kth->next;

            // Step 3: Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }

            // Step 4: Connect reversed group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};