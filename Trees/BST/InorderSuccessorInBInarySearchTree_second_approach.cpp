/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int get_index_of_x(vector<int>& inorder, int x){
        int low = 0; int high = inorder.size();
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(inorder[mid] == x){
                return mid;
            }
            else if(inorder[mid] > x){
                // eliminate the right search space
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        // yahan tak control kabhi nahi pahuchega
        return -1;
    }
    void inorder_traversal(Node* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }
        inorder_traversal(root->left, inorder);
        inorder.push_back(root->data);
        inorder_traversal(root->right, inorder);
    }
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        // This can be done in 2 steps 
        // first find out the inorder traversal
        // and then return the sucessor if exists 
        
        vector<int> inorder;
        inorder_traversal(root, inorder);
        
        // we can use binary search to find out the ele ka index
        int index = get_index_of_x(inorder, x->data);
        
        if(index < inorder.size() - 1){
            return inorder[index + 1];
        }else{
            return -1;
        }
    }
};