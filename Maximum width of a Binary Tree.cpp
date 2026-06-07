class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});
        long long maxi = 0;

        while(!q.empty()){                       
            int n = q.size();

            long long mini = q.front().second; 

            long long first = q.front().second - mini;
            long long last  = q.back().second  - mini;

            maxi = max(maxi, last - first + 1);

            while(n--){
                auto it = q.front(); 
                q.pop();

                TreeNode* node = it.first;
                long long x = it.second - mini; 

                if(node->left) q.push({node->left, 2*x+1});
                if(node->right) q.push({node->right, 2*x+2});
            }
        }

        return (int)maxi;
    }
};
