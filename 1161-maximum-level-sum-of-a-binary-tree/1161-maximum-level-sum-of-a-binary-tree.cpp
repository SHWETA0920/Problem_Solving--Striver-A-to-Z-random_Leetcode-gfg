class Solution {
public:     
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL) return 0;
        int sum=0;
        int maxi=root->val;
        int maxLevel = 1;   
        int currentLevel = 1;
        q.push(root);
        int count=0;
        while(!q.empty()){
            int n=q.size();
            sum=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                sum+=q.front()->val;
                
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if (sum > maxi) {
                maxi = sum;
                maxLevel = currentLevel;
            }
            
            currentLevel++;
        }
        return maxLevel;        
    }
};