class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushAllLeft(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();

      
        if (temp->right != NULL) {
            pushAllLeft(temp->right);
        }

        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};