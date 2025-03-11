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
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == NULL) return NULL;
    
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            } 
            else if (key > root->val) {
                root->right = deleteNode(root->right, key);
            } 
            else {
                // Node found, handle three cases:
                if (root->left == NULL) {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                } 
                else if (root->right == NULL) {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                } 
                else {
                    // Find inorder successor (smallest node in right subtree)
                    TreeNode* parent = root;
                    TreeNode* successor = root->right;
    
                    while (successor->left != NULL) {
                        parent = successor;
                        successor = successor->left;
                    }
    
                    // If the successor is not the direct right child
                    if (parent != root) {
                        parent->left = successor->right; // Relink successor's right subtree
                        successor->right = root->right;
                    }
    
                    successor->left = root->left; // Attach left subtree of root
                    delete root;
                    return successor;
                }
            }
            return root;
        }
    };