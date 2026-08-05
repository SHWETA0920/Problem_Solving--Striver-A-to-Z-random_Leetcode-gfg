class Solution {
public:

    bool sameTree(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;

        if(root1 == NULL || root2 == NULL)
            return false;

        if(root1->val != root2->val)
            return false;

        return sameTree(root1->left, root2->left) &&
               sameTree(root1->right, root2->right);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL)
            return false;

        // check current node
        if(sameTree(root, subRoot))
            return true;

        // search left and right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};