class Solution {
public:
    int helper(TreeNode* root, int curr) {
        if (root == NULL) return 0;

        curr = curr * 10 + root->val;

        if (root->left == NULL && root->right == NULL) {
            return curr;
        }

        return helper(root->left, curr) +
               helper(root->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};