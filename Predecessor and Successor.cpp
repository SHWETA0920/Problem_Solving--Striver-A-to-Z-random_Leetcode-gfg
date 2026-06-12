class Solution {
  public:
    Node* ios(Node* root,int k){
      Node* succ=NULL;
       while(root){
           if(k>=root->data) root=root->right;
           else{
               succ=root;
               root=root->left;
           }
       }
       return succ;
       
   }
   Node* iop(Node* root,int k){
       Node* pred=NULL;
       while(root){
           if(k<=root->data) root=root->left;
           else{
               pred=root;
               root=root->right;
           }
       }
       return pred;
       
   }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*>ans;
        Node* ans1=iop(root,key);
        Node* ans2=ios(root,key);
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};
