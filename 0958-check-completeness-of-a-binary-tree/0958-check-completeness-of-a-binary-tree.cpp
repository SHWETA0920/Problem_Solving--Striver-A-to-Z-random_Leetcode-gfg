class Solution {
public:
    bool levelOrder(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool missing = false;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                missing = true;
            } 
            else {
                if (missing) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }

    bool isCompleteTree(TreeNode* root) {
        return levelOrder(root);
    }
};