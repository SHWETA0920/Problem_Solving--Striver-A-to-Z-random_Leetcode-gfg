class Solution {
  public:
    unordered_map<Node*, Node*> parents;
    int tar;
    Node* targetNode;

    void dfs(Node* root){
        if(root == NULL) return;

        if(root->data == tar) targetNode = root;

        if(root->left){
            parents[root->left] = root;
            dfs(root->left);
        }
        if(root->right){
            parents[root->right] = root;
            dfs(root->right);
        }
    }

    int minTime(Node* root, int target) {
    tar = target;
    targetNode = NULL;
    dfs(root);

    queue<Node*> q;
    set<Node*> burned;

    q.push(targetNode);
    burned.insert(targetNode);

    int time = 0;

    while(!q.empty()){
        int n = q.size();
        bool burnedSomething = false;

        while(n--){
            Node* curr = q.front();
            q.pop();

            if(curr->left && burned.find(curr->left) == burned.end()){
                q.push(curr->left);
                burned.insert(curr->left);
                burnedSomething = true;
            }

            if(curr->right && burned.find(curr->right) == burned.end()){
                q.push(curr->right);
                burned.insert(curr->right);
                burnedSomething = true;
            }

            if(parents[curr] && burned.find(parents[curr]) == burned.end()){
                q.push(parents[curr]);
                burned.insert(parents[curr]);
                burnedSomething = true;
            }
        }

        if(burnedSomething) time++;
    }

    return time;
}
