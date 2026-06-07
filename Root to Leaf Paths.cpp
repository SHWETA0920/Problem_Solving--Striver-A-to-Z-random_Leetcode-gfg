class Solution {
public:
    void preorder(Node* root, vector<int>& arr, vector<vector<int>>& ans) {
        if(!root) return;

        arr.push_back(root->data);
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(arr);
        }

        preorder(root->left, arr, ans);
        preorder(root->right, arr, ans);

        arr.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> arr;

        preorder(root, arr, ans);

        return ans;
    }
};
