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
            first->next = temp;
            first = first->next;
            if (temp1 != NULL) {
                second->next = temp1;
                second = second->next;            
                temp = temp1->next;}
            else
                temp = NULL;
            if (temp != NULL)
                temp1 = temp->next;
            else
                temp1 = NULL;
        }
        second->next = NULL;
        first->next = s->next;

        return f->next;
    }
};