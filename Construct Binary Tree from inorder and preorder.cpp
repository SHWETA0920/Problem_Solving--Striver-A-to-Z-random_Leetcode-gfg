class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,
                    int instart, int inend,
                    int poststart, int postend) {
        
        if(instart > inend || poststart > postend) return NULL;

        TreeNode* root = new TreeNode(preorder[poststart]);

        int i = instart;
        for(; i <= inend; i++){
            if(inorder[i] == root->val) break;
        }

        int leftsize = i - instart;

        root->left = solve(inorder, preorder,
                           instart, i-1,
                           poststart+1, poststart + leftsize);

        root->right = solve(inorder, preorder,
                            i+1, inend,
                            poststart + leftsize + 1, postend);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        return solve(in, pre, 0, n-1, 0, n-1);
    }
};
