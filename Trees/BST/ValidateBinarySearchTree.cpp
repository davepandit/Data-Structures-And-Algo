// Note this is not the optimised code 
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
        void inorder(TreeNode* root, vector<int>& res){
            if(root == NULL){
                return;
            }
    
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
        bool isValidBST(TreeNode* root) {
            // Algorithm 
            // 1. Do the inorder traversal and store the ele in a vector
            // 2. Traverse through the vector and then just see that whether the ele are sorted or not
            vector<int> res;
            inorder(root, res);
            // res contains the inorder traversal 
            for(int i = 0; i < res.size() - 1; i++){
                if(res[i] < res[i + 1]){
                    continue;
                }
                else{
                    return false;
                }
            }
    
            return true;
        }
    };