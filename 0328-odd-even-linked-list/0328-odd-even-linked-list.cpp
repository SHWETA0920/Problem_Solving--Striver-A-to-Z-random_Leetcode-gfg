class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;
        ListNode* temp1 = head->next;

        ListNode* f = new ListNode(-1);
        ListNode* s = new ListNode(0);

        ListNode* first = f;
        ListNode* second = s;

        while (temp != NULL) {

            // odd
            first->next = temp;
            first = first->next;

            // even
            if (temp1 != NULL) {
                second->next = temp1;
                second = second->next;
            }

            // move to next odd
            if (temp1 != NULL)
                temp = temp1->next;
            else
                temp = NULL;

            // move to next even
            if (temp != NULL)
                temp1 = temp->next;
            else
                temp1 = NULL;
        }

        // terminate both lists
        //first->next = NULL;
        second->next = NULL;

        // connect
        first->next = s->next;

        return f->next;
    }
};