
class Solution {
public:
    TreeNode* ans = nullptr;

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left, p, q);
        int right = dfs(root->right, p, q);

        int self = (root == p || root == q) ? 1 : 0;

        int total = left + right + self;

        if (total == 2 && ans == nullptr) {
            ans = root;
        }

        return total;
    }

    TreeNode* lowestCommonAncestor(
        TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root, p, q);
        return ans;
    }
};