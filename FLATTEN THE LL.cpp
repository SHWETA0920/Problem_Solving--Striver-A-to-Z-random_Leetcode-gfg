class Solution {
  public:
    Node* merge(Node* head1, Node* head2){
        Node* dummy = new Node(0);
        Node* temp = dummy;

        while(head1 && head2){
            if(head1->data <= head2->data){
                temp->bottom = head1;
                head1 = head1->bottom;
            } else {
                temp->bottom = head2;
                head2 = head2->bottom;
            }
            temp = temp->bottom;
        }

        if(head1) temp->bottom = head1;
        else temp->bottom = head2;

        return dummy->bottom;
    }

    Node *flatten(Node *root) {
        if(!root || !root->next) return root;

        root->next = flatten(root->next);

        return merge(root, root->next);
    }
};
