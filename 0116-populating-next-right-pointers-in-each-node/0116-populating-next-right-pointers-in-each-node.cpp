class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        Node* level = root;

        while (level->left) { 
            Node* curr = level;

            while (curr) {

               
                curr->left->next = curr->right;

                if (curr->next) {
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            level = level->left; // move to next level
        }

        return root;
    }
};