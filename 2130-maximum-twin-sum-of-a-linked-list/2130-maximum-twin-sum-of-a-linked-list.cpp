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
    ListNode* rev(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(temp){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;

        
    }
    int pairSum(ListNode* head) {
        int n=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;            
        }
        ListNode* first=head;
        ListNode* second=head;
        ListNode* node=head;
        int y=n/2;
        while(y--){
            node=second;
            second=second->next;
        }
        node->next=NULL;
        int maxi=0;
        ListNode *second1=rev(second);
        while(first !=NULL && second1!=NULL){
            maxi=max(maxi,first->val+second1->val);
            first=first->next;
            second1=second1->next;
        }
        return maxi;        
    }
};