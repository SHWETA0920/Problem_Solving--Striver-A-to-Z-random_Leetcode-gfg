

class Solution {
  public:
    int minValue(Node* root) {
        if(!root) return 0;
        int mini=root->data;
        Node* temp= root;
        while(temp->left) {
            temp=temp->left;
            mini=min(mini,temp->data);
        }
        return mini;
    }
};
