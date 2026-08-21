class Solution {
public:

    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        // Step 1: Insert copied node after every original node
        Node* temp = head;

        while (temp != NULL) {

            Node* copy = new Node(temp->val);

            copy->next = temp->next;
            temp->next = copy;

            temp = copy->next;
        }


        // Step 2: Set random pointers of copied nodes
        temp = head;

        while (temp != NULL) {

            Node* copy = temp->next;

            if (temp->random != NULL)
                copy->random = temp->random->next;
            else
                copy->random = NULL;

            temp = copy->next;
        }


        // Step 3: Separate original and copied lists
        temp = head;

        Node* copyHead = head->next;

        while (temp != NULL) {

            Node* copy = temp->next;

            temp->next = copy->next;

            if (copy->next != NULL)
                copy->next = copy->next->next;
            else
                copy->next = NULL;

            temp = temp->next;
        }

        return copyHead;
    }
};