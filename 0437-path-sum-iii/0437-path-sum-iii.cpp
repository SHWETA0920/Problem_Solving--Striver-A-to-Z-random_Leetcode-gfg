class Solution {
public:
    int solve(TreeNode* root, long long targetSum) {
        if (root == NULL)
            return 0;
        int count = 0;
        if (root->val == targetSum)
            count++;
        count += solve(root->left, targetSum - root->val);
        count += solve(root->right, targetSum - root->val);
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;

        int count = 0;
        count += solve(root, targetSum);
       
        count += pathSum(root->left, targetSum);
        
        count += pathSum(root->right, targetSum);

        return count;
    }
};