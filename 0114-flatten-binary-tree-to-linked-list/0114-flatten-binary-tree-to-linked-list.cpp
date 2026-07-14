class Solution {
public:
    TreeNode* flatten1(TreeNode* root){
        if(root == NULL) return NULL;

        TreeNode* left = flatten1(root->left);
        root->left = NULL;
        TreeNode* right = flatten1(root->right);

        

        if(left){
            root->right = left;
            TreeNode* temp = left;
            while(temp->right){
                temp = temp->right;
            }
            temp->right = right;
        }
        else{
            root->right = right;
        }

        return root;
    }

    void flatten(TreeNode* root) {
        flatten1(root);
    }
};