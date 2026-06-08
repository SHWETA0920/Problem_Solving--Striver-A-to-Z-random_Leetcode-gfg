class Solution {
  public:
    bool isleaf(Node* root){
        if(root == NULL) return false;
        if(root->left==NULL && root->right==NULL) return true;
        else return false;
    }
    bool isSumProperty(Node *root) {
        if(root==NULL) return true;
        if(isleaf(root)) return true;
        int l=0,ri=0;
        if(root->left) l=root->left->data;
        if(root->right) ri=root->right->data;
        if(root->data !=(l+ri)) return false;
        return isSumProperty(root->left)&& isSumProperty(root->right);
        
    }
};
