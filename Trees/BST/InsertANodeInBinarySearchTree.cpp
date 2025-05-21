/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // create a new node out of the ele give 
        TreeNode* new_node = new TreeNode(val);

        if(root == NULL){
            return new_node;
        }

        // new_node will always be inserted at the leaf position 
        TreeNode* node = root;
        TreeNode* last_node = NULL;

        while(node){
            if(node->val > val){
                last_node = node;
                // eliminate the right search space 
                node = node->left;
            }
            else if(node->val < val){
                last_node = node;
                // eliminate the left search space 
                node = node->right;
            }
        }

        // node is null but the last_node is pointing to the ele jahan we need to attach the ele
        // simply we need to check the below condition 
        if(last_node->val < val){
            // attach to the right of it 
            last_node->right = new_node;
        } 
        else{
            // attach to the left 
            last_node->left = new_node;
        }

        return root;
    }
};