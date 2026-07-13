class Solution {
public:
    int maxSum = 0;

    struct NodeValue {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    NodeValue solve(TreeNode* root) {
        // Base case
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.isBST && right.isBST && 
            root->val > left.maxVal && root->val < right.minVal) {

            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);

            return {
                true,
                currSum,
                min(root->val, left.minVal),
                max(root->val, right.maxVal)
            };
        }

        
        return {false, 0, INT_MIN, INT_MAX};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};