// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        if(root == NULL){
            return -1;
        }
        Node* node = root;
        int ans = -1;
        while(node){
            if(node->data <= x){
                ans = node->data;
                // eliminate the left search space 
                node = node->right;
            }
            else{
                // eliminate the right search space
                node = node->left;
            }
        }
        
        return ans;
        
    }
};