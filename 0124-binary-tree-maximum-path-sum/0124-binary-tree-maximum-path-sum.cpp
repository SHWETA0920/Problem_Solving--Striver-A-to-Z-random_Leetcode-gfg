/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum;
    int solve(TreeNode* root){
        if(root ==NULL) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int ans1=max(l,r)+root->val;
        int ans2=root->val;
        int ans3=l+r+root->val;
        maxSum=max({maxSum,ans1,ans2,ans3});
        return max(ans1,ans2);
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;        
    }
};