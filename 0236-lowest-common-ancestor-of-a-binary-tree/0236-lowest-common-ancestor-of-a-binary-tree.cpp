class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode* left_n=lowestCommonAncestor(root->left,p,q);
        TreeNode* right_n=lowestCommonAncestor(root->right,p,q);
        if(left_n!=NULL && right_n!=NULL) return root;
        if(left_n!=NULL) return left_n;
        return right_n;

        
    }
};