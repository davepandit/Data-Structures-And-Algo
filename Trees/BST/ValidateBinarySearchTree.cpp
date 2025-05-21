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
    bool solve(TreeNode* root, long min_val, long max_val){
        if(root == NULL){
            return true;
        }
        if(root->val >= max_val || root->val <= min_val){
            return false;
        }
        bool lp = solve(root->left, min_val, root->val);
        bool rp = solve(root->right, root->val, max_val);

        return (lp && rp);
    }
    bool isValidBST(TreeNode* root) {
        // Algorithm - Every node is in between some range 
        long min_val = LONG_MIN;
        long max_val = LONG_MAX;
        return solve(root, min_val, max_val);
        
    }
};