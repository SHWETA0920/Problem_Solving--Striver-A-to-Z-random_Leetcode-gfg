class Solution {
public:
    void get(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        // If leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->val);
            return;
        }

        // Traverse left subtree
        if (root->left) {
            get(root->left, ans);
        }

        // Traverse right subtree
        if (root->right) {
            get(root->right, ans);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;

        get(root1, ans1);
        get(root2, ans2);

        if (ans1.size() != ans2.size())
            return false;

        for (int i = 0; i < ans1.size(); i++) {
            if (ans1[i] != ans2[i])
                return false;
        }

        return true;
    }
};