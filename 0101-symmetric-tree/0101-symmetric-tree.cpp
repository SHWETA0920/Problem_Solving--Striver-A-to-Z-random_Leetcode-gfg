
class Solution {
public:
    bool check(TreeNode* l ,TreeNode* r){
    if(!l && !r) return true;   
    if(!l || !r) return false;  
    
    return (l->val == r->val) &&
           check(l->left, r->right) &&
           check(l->right, r->left);
}
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left,root->right);
        
    }
};