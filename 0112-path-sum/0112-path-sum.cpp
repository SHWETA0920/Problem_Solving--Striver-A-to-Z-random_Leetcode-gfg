
class Solution {
public:
    bool res = false;

    void isans(TreeNode* root, int sum, int target) {
        if (root == nullptr) return;

        sum += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == target) {
                res = true;
                return;
            }
        }

        isans(root->left, sum, target);
        isans(root->right, sum, target);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        res = false;
        isans(root, 0, targetSum);
        return res;
    }
};