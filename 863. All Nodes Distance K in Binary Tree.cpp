class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parents;

    void solve(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            parents[root->left] = root;
            solve(root->left);
        }
        if (root->right) {
            parents[root->right] = root;
            solve(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        solve(root);

        queue<TreeNode*> q;
        set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int dist = 0;
        while (!q.empty()) {
            int n = q.size();

            if (dist == k) break;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parents[node] && !visited.count(parents[node])) {
                    q.push(parents[node]);
                    visited.insert(parents[node]);
                }
            }

            dist++;
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
