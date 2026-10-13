
class Solution {
public:
    // Returns the next smallest node
    TreeNode* ascending(stack<TreeNode*>& st) {
        TreeNode* curr = st.top();
        st.pop();

        TreeNode* node = curr->right;

        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }

        return curr;
    }

    // Returns the next largest node
    TreeNode* descending(stack<TreeNode*>& st) {
        TreeNode* curr = st.top();
        st.pop();

        TreeNode* node = curr->left;

        while (node != nullptr) {
            st.push(node);
            node = node->right;
        }

        return curr;
    }

    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;

        stack<TreeNode*> s1, s2;

        TreeNode* curr = root;

        // Initialize ascending stack
        while (curr != nullptr) {
            s1.push(curr);
            curr = curr->left;
        }

        curr = root;

        // Initialize descending stack
        while (curr != nullptr) {
            s2.push(curr);
            curr = curr->right;
        }

        TreeNode* left = s1.top();
        TreeNode* right = s2.top();

        while (left != right && left->val < right->val) {
            int sum = left->val + right->val;

            if (sum == k)
                return true;

            else if (sum < k)
                left = ascending(s1);

            else
                right = descending(s2);
        }

        return false;
    }
};