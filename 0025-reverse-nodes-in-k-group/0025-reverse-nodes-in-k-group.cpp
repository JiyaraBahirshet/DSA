/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1){
            return head;
        }
        ListNode* temp=head;
        for(int i=0;i<k;i++){
            if(temp==NULL){
                return head;
            }
            temp=temp->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        for(int i=0;i<k;i++){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};