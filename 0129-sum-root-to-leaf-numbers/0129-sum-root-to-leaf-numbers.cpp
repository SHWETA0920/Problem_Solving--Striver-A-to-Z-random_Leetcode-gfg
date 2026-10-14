class Solution {
public:
    void helper(TreeNode* root, vector<int> v, vector<vector<int>>& ans) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            v.push_back(root->val);
            ans.push_back(v);
            return;
        }

        v.push_back(root->val);
        helper(root->left, v, ans);
        helper(root->right, v, ans);
    }

    int sumNumbers(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;

        helper(root, v, ans);

        int sum = 0;

        for (int i = 0; i < ans.size(); i++) {
            int no = 0;

            for (int j = 0; j < ans[i].size(); j++) {
                no = no * 10;
                no += ans[i][j];
            }

            sum += no;
        }

        return sum;
    }
};