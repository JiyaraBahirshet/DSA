
class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Insert first node of every non-empty list
        for(auto it : lists) {
            if(it != NULL) {
                pq.push(it);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()) {

            ListNode* node = pq.top();
            pq.pop();

            // Insert next node into heap
            if(node->next != NULL) {
                pq.push(node->next);
            }

            // Attach current smallest node
            temp->next = node;
            temp = temp->next;
        }

        temp->next = NULL;

        return dummy->next;
    }
};
