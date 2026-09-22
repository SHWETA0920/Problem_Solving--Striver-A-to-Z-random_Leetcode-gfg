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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* a=head;
        ListNode* b=head->next;
        while(b!=NULL){
            while(b!=NULL && a->val==b->val){
                b=b->next;
                a->next=b;   
            }
           a=a->next;
           if(b!=NULL) b=b->next;                    
        }
        return head;
    }
};