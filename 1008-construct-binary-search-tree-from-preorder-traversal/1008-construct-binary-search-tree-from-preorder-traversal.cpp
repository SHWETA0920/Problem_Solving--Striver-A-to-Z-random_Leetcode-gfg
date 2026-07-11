class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {        
        if(pre.size() == 0) return NULL;

        TreeNode* ans = new TreeNode(pre[0]);

        for(int i = 1; i < pre.size(); i++){
            TreeNode* temp = ans;

            while(true){
                if(pre[i] < temp->val){
                    if(temp->left == NULL){
                        temp->left = new TreeNode(pre[i]);
                        break;
                    }
                    temp = temp->left;
                }
                else{
                    if(temp->right == NULL){
                        temp->right = new TreeNode(pre[i]);
                        break;
                    }
                    temp = temp->right;
                }
            }
        }

        return ans;
    }
};