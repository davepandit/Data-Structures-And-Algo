/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode* node = root;
        while(node){
            if(node->val < p->val && node->val < q->val){
                // move to the right
                node = node->right;
            }
            else if(node->val > p->val && node->val > q->val){
                // move to the left
                node = node->left;
            }
            else{
                return node;
            }
        }

        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return root;
        }

        TreeNode* ans = solve(root, p, q);

        return ans;
    }
};