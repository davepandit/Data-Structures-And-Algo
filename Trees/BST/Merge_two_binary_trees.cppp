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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL){
            return NULL;
        }

        int val1 = root1 ? root1->val : 0;
        int val2 = root2 ? root2->val : 0;

        // create a new node 
        TreeNode* root = new TreeNode(val1 + val2);

        // do the same thing for the left subtree and for the right subtree
        root->left = mergeTrees(root1 ? root1->left : NULL, root2 ? root2->left : NULL);
        root->right = mergeTrees(root1 ? root1->right : NULL, root2 ? root2->right : NULL);

        return root;
    }
};