class Solution {
public:
    void good(TreeNode* root, int maxi, int &count) {
        if (root == NULL) return;

        if (root->val >= maxi) {
            count++;
            maxi = root->val;
        }

        if (root->left)
            good(root->left, maxi, count);

        if (root->right)
            good(root->right, maxi, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        int maxi = root->val;

        good(root, maxi, count);

        return count;
    }
};