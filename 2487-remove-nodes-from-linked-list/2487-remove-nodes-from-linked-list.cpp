class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {

        head = reverse(head);

        int maxi = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr) {

            if (curr->val >= maxi) {
                maxi = curr->val;
                prev = curr;
            } else {
                prev->next = curr->next;
            }

            curr = curr->next;
        }

        return reverse(head);
    }
};