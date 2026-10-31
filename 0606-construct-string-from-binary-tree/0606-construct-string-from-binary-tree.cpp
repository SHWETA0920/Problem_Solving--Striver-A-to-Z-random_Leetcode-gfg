class Solution {
public:
    bool isleaf(TreeNode* root) {
        return root->left == NULL && root->right == NULL;
    }

    void solve(TreeNode* root, string &s) {
        if(root == nullptr) {
            return;
        }

        s += to_string(root->val);

        if(isleaf(root)) {
            return;
        }

        if(root->left != nullptr) {
            s += "(";
            solve(root->left, s);
            s += ")";
        }
        else if(root->right != nullptr) {
            s += "()";
        }

        if(root->right != nullptr) {
            s += "(";
            solve(root->right, s);
            s += ")";
        }
    }

    string tree2str(TreeNode* root) {
        string s = "";
        solve(root, s);
        return s;
    }
};