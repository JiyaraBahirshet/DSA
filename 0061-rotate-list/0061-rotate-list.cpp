
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }

        ListNode* temp = head;
        int n = 1;

        // Find length and tail
        while(temp->next != NULL){
            n++;
            temp = temp->next;
        }

        // Reduce unnecessary rotations
        k = k % n;

        if(k == 0){
            return head;
        }

        // Make the list circular
        temp->next = head;

        // Find new tail
        int steps = n - k;
        ListNode* newTail = head;

        for(int i = 1; i < steps; i++){
            newTail = newTail->next;
        }

        // New head is next of new tail
        ListNode* newHead = newTail->next;

        // Break the circular list
        newTail->next = NULL;

        return newHead;
    }
};
