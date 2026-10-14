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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL) return 0;
        q.push(root);
        int depth=0;
        int mini=INT_MAX;
        while(q.size()>0){            
            int n=q.size();
            depth++;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                if(node->left==NULL && node->right==NULL) mini=min(depth,mini);
            }
        }
        return mini;        
    }
};